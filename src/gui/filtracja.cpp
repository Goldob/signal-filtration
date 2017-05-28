#include <QFileDialog>
#include <QMessageBox>

#include "ui_filtracja.h"

#include "filtracja.h"
#include "about_dialog.h"
#include "signal.h"

Filtracja::Filtracja (QWidget *parent) :
    QMainWindow(parent), ui(new Ui::Filtracja) {

    aboutDialog = new AboutDialog;
    ui->setupUi(this);
}

Filtracja::~Filtracja () {
    delete ui;
}

void Filtracja::on_actionOpen_triggered () {
    QString fileName = QFileDialog::getOpenFileName(this);

    if (!fileName.isEmpty()) {
        dsp::readSignalFromFile(fileName.toStdString(), in_signal);
        save_fileName = fileName;
        onSignalOpened();
    }
}

void Filtracja::on_actionSave_triggered () {
    dsp::saveSignalToFile(save_fileName.toStdString(), out_signal);
}

void Filtracja::on_actionSaveAs_triggered () {
    QString fileName = QFileDialog::getSaveFileName(this);

    if (!fileName.isEmpty()) {
        dsp::saveSignalToFile(fileName.toStdString(), out_signal);
        save_fileName = fileName;
    }
}

void Filtracja::on_actionAbout_triggered () {
    aboutDialog->show();
}

void Filtracja::onSignalOpened () {
    out_signal = in_signal;

    ui->actionSave->setEnabled(true);
    ui->actionSaveAs->setEnabled(true);
}
