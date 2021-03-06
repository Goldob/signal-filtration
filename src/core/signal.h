/* File signal.h */
#ifndef SIGNAL_INCLUDED
#define SIGNAL_INCLUDED

#define NONPOSITIVE_FREQ_ERROR 0

enum SignalIOException {
    STREAM_NOT_OPEN,
    NONPOSITIVE_FREQ,
    NONPOSITIVE_SAMPLE_NUM,
    PREMATURE_EOF
};

#include <string>

#include "list.h"

namespace dsp {
    typedef double freq;    //!< Częstotliwość wyrażona w hercach.
    typedef double sample;  //!< Ogólnie rozumiana próbka sygnału. Może byc interpretowana dowolnie w zależnosci od zastosowania.

    /*!
     * \brief Struktura \c signal jest standardową reprezentacją sygnału w domenie czasu.
     */
    struct signal {
        freq samplingFreq;      //!< Częstotliowość próbkowania - ilość próbek na sekundę.
        List<sample> samples;   //!< Lista wszystkich próbek sygnału.
    };

    /*!
     * \brief Wczytaj sygnał z pliku o podanej nazwie.
     * \param fileName Nazwa pliku.
     * \param out_signal Wczytany sygnał, przekazany przez referencję.
     */
    void readSignalFromFile (const std::string fileName,
                             signal& out_signal);
  
    /*!
     * \brief Zapisz sygnał do pliku o podanej nazwie.
     * \param fileName Nazwa pliku.
     * \param in_signal Sygnał do zapisania.
     */
    void saveSignalToFile (const std::string fileName,
                           const signal in_signal);
}

#endif /* !SIGNAL_INCLUDED */
