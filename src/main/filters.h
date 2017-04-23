/* File filters.h */
#ifndef FILTERS_INCLUDED
#define FILTERS_INCLUDED

#include "signal.h"

namespace sig {
  void lowPassFilter (const signal in_signal,
                      const freq freq_upperBound,
                      signal& out_signal);

  void highPassFilter (const signal in_signal,
                       const freq freq_lowerBound,
                       signal& out_signal);

  void bandPassFilter (const signal in_signal,
                       const freq freq_lowerBound,
                       const freq freq_upperBound,
                       signal& out_signal);

  void bandStopFilter (const signal in_signal,
                       const freq freq_lowerBound,
                       const freq freq_upperBound,
                       signal& out_signal);
}

#endif /* !FILTERS_INCLUDED */
