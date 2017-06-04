#include <QApplication>
#include <QMainWindow>
#include <QMetaType>

#include "filtracja.h"

int main (int argc, char *argv[])
{
    qRegisterMetaType<dsp::signal>("dsp::signal");
    qRegisterMetaType<dsp::filter>("dsp::filter");

    QApplication app(argc, argv);

    Filtracja filtracja;
    filtracja.show();

    return app.exec();
}
