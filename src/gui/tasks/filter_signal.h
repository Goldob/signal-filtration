/* File filter_signal.h */
#ifndef FILTER_SIGNAL_INCLUDED
#define FILTER_SIGNAL_INCLUDED

#include "task.h"
#include "signal.h"
#include "filters.h"

/*!
 * \brief Klasa FilterSignalTask reprezentuje asynchroniczne zadanie filtracji sygnału.
 */
class FilterSignalTask : public Task {
    Q_OBJECT

    public:
        /*!
         * \brief Tworzy nową instancję zadania ze wskazanymi parametrami.
         * \param input Sygnał wejściowy.
         * \param filter Filtr do nałożenia na syngał.
         */
        FilterSignalTask (dsp::signal input, dsp::filter filter);

        /*!
         * \brief Wykonuje zadaną filtrację sygnału i po jej zakończeniu emituje sygnał \c done.
         */
        void run ();

    private:
        dsp::signal m_input;
        dsp::filter m_filter;

    signals:
        /*!
         * \brief Ten sygnał zostaje wyemitowany po zakończeniu filtracji.
         * \param output Sygnał wyjściowy.
         */
        void done (dsp::signal output);
};

#endif /* !FILTER_SIGNAL_INCLUDED */
