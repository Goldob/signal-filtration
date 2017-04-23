/* File fourier.h */
#ifndef FOURIER_INCLUDED
#define FOURIER_INCLUDED

#include "signal.h"

namespace sig {
  struct fourierSeries {
    int n;
    double * evenCoefficients;
    double * oddCoefficients;
  };

  void fourierTransform (const signal in_signal,
                         const freq maxFreq,
                         fourierSeries& out_fourierSeries);

  void inverseFourierTransform (const fourierSeries in_fourierSeries,
                                signal& out_signal);
}

#endif /* !FOURIER_INCLUDED */
