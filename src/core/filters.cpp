#include "signal.h"
#include "fourier.h"

namespace sig {
  void lowPassFilter (const signal in_signal,
                      const freq freq_upperBound,
                      signal& out_signal) {
      sig::signal_freqDomain signal_freq;
      sig::fourierTransform(in_signal, signal_freq);

      // TODO

      sig::inverseFourierTransform(signal_freq, out_signal);
  }

  void highPassFilter (const signal in_signal,
                       const freq freq_lowerBound,
                       signal& out_signal) {
      sig::signal_freqDomain signal_freq;
      sig::fourierTransform(in_signal, signal_freq);

      // TODO

      sig::inverseFourierTransform(signal_freq, out_signal);
  }

  void bandPassFilter (const signal in_signal,
                       const freq freq_lowerBound,
                       const freq freq_upperBound,
                       signal& out_signal) {
      sig::signal_freqDomain signal_freq;
      sig::fourierTransform(in_signal, signal_freq);

      // TODO

      sig::inverseFourierTransform(signal_freq, out_signal);
  }

  void bandStopFilter (const signal in_signal,
                       const freq freq_lowerBound,
                       const freq freq_upperBound,
                       signal& out_signal) {
      sig::signal_freqDomain signal_freq;
      sig::fourierTransform(in_signal, signal_freq);

      // TODO

      sig::inverseFourierTransform(signal_freq, out_signal);
  }
}
