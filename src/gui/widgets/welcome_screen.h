/* File dropdown_area.h */
#ifndef WELCOME_SCREEN_INCLUDED
#define WELCOME_SCREEN_INCLUDED

#include <QWidget>

class WelcomeScreen : public QWidget {
    Q_OBJECT

    public:
        WelcomeScreen (QWidget * parent = nullptr);
        ~WelcomeScreen ();

    signals:
        void fileDropped (QString fileName);
};

#endif /* !WELCOME_SCREEN_INCLUDED */
