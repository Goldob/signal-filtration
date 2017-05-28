#include <QApplication>
#include <QMainWindow>

#include "filtracja.h"

int main (int argc, char *argv[])
{
    QApplication app(argc, argv);

    Filtracja filtracja;
    filtracja.show();

    return app.exec();
}
