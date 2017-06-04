#define CRITICAL_MSGBOX_TITLE "Wystąpił błąd"

#include <QFileDialog>
#include <QMessageBox>

#include "ui_filtracja.h"
#include "filtracja.h"

Filtracja::Filtracja (QWidget * parent) : QMainWindow(parent) {
    m_ui->setupUi(this);
}

Filtracja::~Filtracja () {
    delete m_ui;

    // TODO
}

void Filtracja::on_actionOpen_triggered () {
    QString fileName = QFileDialog::getOpenFileName(this);

    if (!fileName.isEmpty()) readFile(fileName);
}

void Filtracja::on_actionSave_triggered () {
    saveFile(m_fileName, m_output);
}

void Filtracja::on_actionSaveAs_triggered () {
    QString fileName = QFileDialog::getSaveFileName(this);

    if (!fileName.isEmpty()) {
        m_fileName = fileName;
        saveFile(fileName, m_output);
    }
}

void Filtracja::on_actionAbout_triggered () {
    m_aboutDialog->show();
}

void Filtracja::cancelTask (Task * task_ptr) {
    task_ptr->blockSignals(true);
    m_globalThreadPool->cancel(task_ptr);
    delete task_ptr;
}

void Filtracja::readFile (QString fileName) {
    if (m_readInProgress) cancelTask(m_readFileTask);

    m_readFileTask = new ReadFileTask(fileName);

    connect(m_readFileTask, &ReadFileTask::success,
            this, &Filtracja::onFileReadSuccess);

    connect(m_readFileTask, &ReadFileTask::failure,
            this, &Filtracja::onFileReadFailure);

    m_globalThreadPool->start(m_readFileTask);
    m_readInProgress = true;
}

void Filtracja::saveFile (QString fileName, dsp::signal input) {
    if (m_saveInProgress) cancelTask(m_saveFileTask);

    m_saveFileTask = new SaveFileTask(fileName, input);

    connect(m_saveFileTask, &SaveFileTask::success,
            this, &Filtracja::onFileSaveSuccess);

    connect(m_saveFileTask, &SaveFileTask::failure,
            this, &Filtracja::onFileSaveFailure);

    m_globalThreadPool->start(m_saveFileTask);
    m_saveInProgress = true;
}

void Filtracja::filterSignal(filter _filter) {
    if (m_filteringInProgress) cancelTask(m_filterSignalTask);

    m_filterSignalTask = new FilterSignalTask(m_input, _filter);

    connect(m_filterSignalTask, &FilterSignalTask::done,
            this, &Filtracja::onSignalFiltered);

    m_globalThreadPool->start(m_filterSignalTask);
    m_filteringInProgress = true;
}

void Filtracja::onFileReadSuccess (QString fileName, dsp::signal output) {
    if (m_filteringInProgress) cancelTask(m_filterSignalTask);

    if (/* some other file is already opened */ !m_fileName.isNull()) {
        m_ui->mainArea->removeWidget(m_filterPreview);
        delete m_filterPreview;
    }

    m_fileName = fileName;

    m_filterControlPanel->reset(output);
    m_filterPreview = new FilterPreview(output, this);

    //connect(m_filterControlPanel, &FilterControlPanel::filterSet,
    //        this, &Filtracja::filterSignal); TODO

    m_ui->mainArea->addWidget(m_filterPreview);
    m_ui->mainArea->setCurrentWidget(m_filterPreview);

    m_ui->filterControlPanel->setEnabled(true);;

    m_ui->actionSave->setEnabled(true);
    m_ui->actionSaveAs->setEnabled(true);

    m_readInProgress = false;
    delete m_readFileTask;
}

void Filtracja::onFileReadFailure (QString errorMessage) {
    QMessageBox::critical(this, CRITICAL_MSGBOX_TITLE, errorMessage);

    m_readInProgress = false;
    delete m_readFileTask;
}

void Filtracja::onFileSaveSuccess () {
    m_saveInProgress = false;
    delete m_saveFileTask;
}

void Filtracja::onFileSaveFailure (QString errorMessage) {
    QMessageBox::critical(this, CRITICAL_MSGBOX_TITLE, errorMessage);

    m_saveInProgress = false;
    delete m_readFileTask;
}

void Filtracja::onSignalFiltered (dsp::signal output) {
    m_filterPreview->updateOutput(output);

    m_filteringInProgress = false;
    delete m_filterSignalTask;
}
