/* File dropdown_area.h */
#ifndef WELCOME_SCREEN_INCLUDED
#define WELCOME_SCREEN_INCLUDED

#define MAIN_LABEL tr("Przeciągnij i upuść plik, aby rozpocząć")

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QMimeData>
#include <QDragEnterEvent>
#include <QDropEvent>

class WelcomeScreen : public QWidget {
    Q_OBJECT

    public:
        WelcomeScreen           (QWidget * parent = nullptr);

    private:
        QVBoxLayout * m_verticalLayout  = new QVBoxLayout(this);
        QLabel      * m_label           = new QLabel(MAIN_LABEL);

    protected:
        void dragEnterEvent     (QDragEnterEvent * event);
        void dropEvent          (QDropEvent * event);

    signals:
        void fileDropped        (QString fileName);
};

#endif /* !WELCOME_SCREEN_INCLUDED */
