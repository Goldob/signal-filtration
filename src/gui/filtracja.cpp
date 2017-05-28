#include "filtracja.h"
#include "about_dialog.h"

#include "ui_filtracja.h"

Filtracja::Filtracja (QWidget *parent) :
    QMainWindow(parent), ui(new Ui::Filtracja) {

    aboutDialog = new AboutDialog;
    ui->setupUi(this);
}

Filtracja::~Filtracja () {
    delete ui;
}

void Filtracja::on_actionAbout_triggered () {
    aboutDialog->show();
}
