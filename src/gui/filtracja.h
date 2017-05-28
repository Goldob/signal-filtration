/* File filtracja.h */
#ifndef FILTRACJA_INCLUDED
#define FILTRACJA_INCLUDED

#include <QMainWindow>

#include "about_dialog.h"

namespace Ui {
    class Filtracja;
}

class Filtracja : public QMainWindow {
    Q_OBJECT

    public:
        explicit Filtracja(QWidget *parent = nullptr);
        ~Filtracja();

    public slots:
        void on_actionAbout_triggered();

    private:
        Ui::Filtracja * ui;
        AboutDialog * aboutDialog;
};

#endif /* !FILTRACJA_INCLUDED */
