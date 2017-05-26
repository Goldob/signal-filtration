#define NULL nullptr

/* File fourier.h */
#ifndef FOURIER_INCLUDED
#define FOURIER_INCLUDED

#include "signal.h"

namespace dsp {
  /*!
   * \brief Struktura \b signal_freqDomain, będaca reprezentacją sygnału
   *        w dziedzinie częstotliwości.
   */
  struct signal_freqDomain {
    freq samplingFreq;          //!< Częstotliwość próbkowania źródłowego sygnału.
    int n;                      //!< Ilość dyskretnych częstotliowości, zależna bezpośrednio od ilości próbek źródłowego sygnału.
    double * realPart   = NULL; //!< Amplitudy sinusów.
    double * imPart     = NULL; //!< Amplitudy cosinusów.
  };

  /*!
   * \brief Przeprowadź dyskretną transformację Fouriera na zadanym sygnale.
   * \param in_signal Sygnał wejściowy.
   * \param out_signal Sygnał wyjściowy w domenie częstotliwości, przekazany przez referencję.
   */
  void fourierTransform (const signal in_signal,
                         signal_freqDomain& out_signal);

  /*!
   * \brief Przeprowadź odwrotną dyskretną transformację Fouriera.
   * \param in_signal Sygnał wejściowy w domenie częstotliwości.
   * \param out_signal Sygnał wyjściowy, przekazany przez referencję.
   */
  void inverseFourierTransform (const signal_freqDomain in_signal,
                                signal& out_signal);
}

#endif /* !FOURIER_INCLUDED */
