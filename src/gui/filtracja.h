/* File filtracja.h */
#ifndef FILTRACJA_INCLUDED
#define FILTRACJA_INCLUDED

#include <QMainWindow>

#include "about_dialog.h"
#include "signal.h"

namespace Ui {
    class Filtracja;
}

class Filtracja : public QMainWindow {
    Q_OBJECT

    public:
        explicit Filtracja (QWidget *parent = nullptr);
        ~Filtracja();

    public slots:
        void on_actionOpen_triggered ();
        void on_actionSave_triggered ();
        void on_actionSaveAs_triggered();
        void on_actionAbout_triggered ();

    private:
        Ui::Filtracja * ui;
        AboutDialog * aboutDialog;

        QString save_fileName;
        dsp::signal in_signal;
        dsp::signal out_signal;

        void onSignalOpened ();
};

#endif /* !FILTRACJA_INCLUDED */
