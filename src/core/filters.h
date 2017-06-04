/* File filters.h */
#ifndef FILTERS_INCLUDED
#define FILTERS_INCLUDED

#include <functional>

#include "signal.h"

namespace dsp {
    /*!
     * \brief Abstrakcja filtra w postaci funkcji sygnału wyjściowego od wejściowego.
     */
    typedef std::function<signal(signal)> filter;

    /*!
     * \brief Zwraca nową instancję filtra dolnoprzepustowego.
     *
     * \param freq_upperBound Górna granica zakresu przepuszczanych częstotliwości.
     */
    filter lowPassFilter (const freq freq_upperBound);

    /*!
     * \brief Zwraca nową instancję filtra górnoprzepustowego.
     *
     * \param freq_lowerBound Dolna granica zakresu przepuszczanych częstotliwości.
     */
    filter highPassFilter (const freq freq_lowerBound);

    /*!
     * \brief Zwraca nową instancję filtra środkowoprzepustowego.
     *
     * \param freq_lowerBound Dolna granica zakresu przepuszczanych częstotliwości.
     * \param freq_upperBound Górna granica zakresu przepuszczanych częstotliwości.
     */
    filter bandPassFilter (const freq freq_lowerBound,
                           const freq freq_upperBound);

    /*!
     * \brief Zwraca nową instancję filtra środkowozaporowego.
     *
     * \param freq_lowerBound Dolna granica zakresu blokowanych częstotliwości.
     * \param freq_upperBound Górna granica zakresu blokowanych częstotliwości.
     */
    filter bandStopFilter (const freq freq_lowerBound,
                           const freq freq_upperBound);
}

#endif /* !FILTERS_INCLUDED */
