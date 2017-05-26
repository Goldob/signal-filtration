/* File filters.h */
#ifndef FILTERS_INCLUDED
#define FILTERS_INCLUDED

#include "signal.h"

namespace dsp {
    /*!
     * \brief Przeprowadź filtrację niskoprzepustową zadanego sygnału.
     *
     * \param in_signal Sygnał wejściowy.
     * \param freq_upperBound Górna granica zakresu przepuszczanych czśstotliwości.
     * \param out_signal Sygnał wyjściowy po filtracji, przekazany przez referencję.
     */
    void lowPassFilter (const signal in_signal,
                        const freq freq_upperBound,
                        signal& out_signal);

    /*!
     * \brief Przeprowadź filtrację wysokoprzepustową zadanego sygnału.
     *
     * \param in_signal Sygnal wejściowy.
     * \param freq_lowerBound Dolna granica zakresu przepuszczanych częstotliwości.
     * \param out_signal Sygnał wyjściowy po filtracji, przekazany przez referencję.
     */
    void highPassFilter (const signal in_signal,
                         const freq freq_lowerBound,
                         signal& out_signal);

    /*!
     * \brief Przeprowadź filtrację środkowoprzepustową zadanego sygnału.
     *
     * \param in_signal Sygnał wejściowy.
     * \param freq_lowerBound Dolna granica zakresu przepuszczanych częstotliwości.
     * \param freq_upperBound Górna granica zakresu przepuszczanych częstotliwości.
     * \param out_signal Sygnał wyjściowy po filtracji, przekazany przez referencję.
     */
    void bandPassFilter (const signal in_signal,
                         const freq freq_lowerBound,
                         const freq freq_upperBound,
                         signal& out_signal);

    /*!
     * \brief Przeprowadź filtrację środkowozaporową zadanego sygnału.
     *
     * \param in_signal Sygnał wejściowy.
     * \param freq_lowerBound Dolna granica zakresu blokowanych częstotliwości.
     * \param freq_upperBound Górna granica zakresu blokowanych częstotliwości.
     * \param out_signal Sygnał wyjściowy po filtracji, przekazany przez referencję.
     */
    void bandStopFilter (const signal in_signal,
                         const freq freq_lowerBound,
                         const freq freq_upperBound,
                         signal& out_signal);
}

#endif /* !FILTERS_INCLUDED */
