/* File save_file.h */
#ifndef SAVE_FILE_INCLUDED
#define SAVE_FILE_INCLUDED

#include "task.h"
#include "signal.h"

/*!
 * \brief Klasa SaveFileTask reprezentuje asynchroniczne zadanie zapisania sygnału do pliku.
 */
class SaveFileTask : public Task {
    Q_OBJECT

    public:
        /*!
         * \brief Tworzy nową instancję zadania ze wskazanymi parametrami.
         * \param fileName Nazwa pliku docelowego.
         * \param input Sygnał do zapisania.
         */
        SaveFileTask (QString fileName, dsp::signal input);

        /*!
         * \brief Zapisuje sygnał do podanego pliku i emituje sygnał \c success lub \c failure.
         */
        void run ();

    private:
        QString m_fileName;
        dsp::signal m_input;

    signals:
        /*!
         * \brief Ten sygnał zostaje wyemitowany, jeśli zapisywanie zakończy się sukcesem.
         */
        void success ();

        /*!
         * \brief Ten sygnał zostaje wyemitowany, jeśli przy zapisywaniu wystąpi błąd.
         * \param errorMessage
         */
        void failure (QString errorMessage);
};

#endif /* !SAVE_FILE_INCLUDED */
