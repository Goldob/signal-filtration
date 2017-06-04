/* File read_file.h */
#ifndef READ_FILE_INCLUDED
#define READ_FILE_INCLUDED

#include "task.h"
#include "signal.h"

/*!
 * \brief Klasa ReadFileTask reprezentuje asynchroniczne zadanie wczytania sygnału z pliku.
 */
class ReadFileTask : public Task {
    Q_OBJECT

    public:
        /*!
         * \brief Tworzy nową instancję zadania ze wskazanymi parametrami.
         * \param fileName Nazwa pliku z sygnałem.
         */
        ReadFileTask (QString fileName);

        /*!
         * \brief Wczytuje sygnał z podanego pliku i emituje sygnał \c success lub \c failure.
         */
        void run ();

    private:
        QString m_fileName;

    signals:
        /*!
         * \brief Ten sygnał zostaje wyemitowany, jeśli wczytywanie zakończy się sukcesem.
         * \param fileName Nazwa pliku z sygnałem.
         * \param output Wczytany sygnał.
         */
        void success (QString fileName, dsp::signal output);

        /*!
         * \brief Ten sygnał zostaje wyemitowany, jeśli przy wczytywaniu wystapi błąd.
         * \param errorMessage Treść błędu.
         */
        void failure (QString errorMessage);
};

#endif /* !READ_FILE_INCLUDED */
