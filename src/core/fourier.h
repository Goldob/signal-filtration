#define NULL nullptr

/* File fourier.h */
#ifndef FOURIER_INCLUDED
#define FOURIER_INCLUDED

#include "signal.h"

namespace sig {
  struct signal_freqDomain {
    freq samplingFreq;
    int n;
    double * realPart   = NULL; // amplitudy sinusów
    double * imPart     = NULL; // amplitudy cosinusów
  };

  void fourierTransform (const signal in_signal,
                         signal_freqDomain& out_signal);

  void inverseFourierTransform (const signal_freqDomain in_signal,
                                signal& out_signal);
}

#endif /* !FOURIER_INCLUDED */
