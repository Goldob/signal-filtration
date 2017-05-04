#include "signal.h"

namespace sig {
  void lowPassFilter (const signal in_signal,
                      const freq freq_upperBound,
                      signal& out_signal) {
    // TODO
  }

  void highPassFilter (const signal in_signal,
                       const freq freq_lowerBound,
                       signal& out_signal) {
    // TODO
  }

  void bandPassFilter (const signal in_signal,
                       const freq freq_lowerBound,
                       const freq freq_upperBound,
                       signal& out_signal) {
    // TODO
  }

  void bandStopFilter (const signal in_signal,
                       const freq freq_lowerBound,
                       const freq freq_upperBound,
                       signal& out_signal) {
    // TODO
  }
}
