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

/*!
 * \brief WelcomeScreen jest widgetem ekranu powitalnego, który wyświetla się przy uruchomieniu programu.
 *        Umożliwia otwieranie plików metodą \e drag&drop.
 */
class WelcomeScreen : public QWidget {
    Q_OBJECT

    public:
        /*!
         * \brief Tworzy nową instancję widgetu.
         */
        WelcomeScreen           (QWidget * parent = nullptr);

    private:
        QVBoxLayout * m_verticalLayout  = new QVBoxLayout(this);
        QLabel      * m_label           = new QLabel(MAIN_LABEL);

    protected:
        void dragEnterEvent     (QDragEnterEvent * event);  //!< \private
        void dropEvent          (QDropEvent * event);       //!< \private

    signals:
        /*!
         * \brief Ten sygnał zostaje wyemitowany, gdy w obszarze widgetu zostanie
         *        upuszczony plik.
         * \param fileName Nazwa pliku.
         */
        void fileDropped        (QString fileName);
};

#endif /* !WELCOME_SCREEN_INCLUDED */
