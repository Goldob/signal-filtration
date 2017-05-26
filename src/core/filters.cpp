#include "signal.h"
#include "fourier.h"

namespace sig {
    inline int freqSampleNumber(signal_freqDomain signal_freq, freq desired_freq) {
        return signal_freq.n * 2 * desired_freq / signal_freq.samplingFreq;
    }

  void lowPassFilter (const signal in_signal,
                      const freq freq_upperBound,
                      signal& out_signal) {
      sig::signal_freqDomain signal_freq;
      sig::fourierTransform(in_signal, signal_freq);

      int upperK = freqSampleNumber(signal_freq, freq_upperBound);

      for (int k = upperK; k < signal_freq.n; k++) {
          signal_freq.realPart[k] = 0;
          signal_freq.imPart[k] = 0;
      }

      sig::inverseFourierTransform(signal_freq, out_signal);
  }

  void highPassFilter (const signal in_signal,
                       const freq freq_lowerBound,
                       signal& out_signal) {
      sig::signal_freqDomain signal_freq;
      sig::fourierTransform(in_signal, signal_freq);

      int lowerK = freqSampleNumber(signal_freq, freq_lowerBound);

      for (int k = 0; k < std::min(lowerK, signal_freq.n); k++) {
          signal_freq.realPart[k] = 0;
          signal_freq.imPart[k] = 0;
      }

      sig::inverseFourierTransform(signal_freq, out_signal);
  }

  void bandPassFilter (const signal in_signal,
                       const freq freq_lowerBound,
                       const freq freq_upperBound,
                       signal& out_signal) {
      sig::signal_freqDomain signal_freq;
      sig::fourierTransform(in_signal, signal_freq);

      int lowerK = freqSampleNumber(signal_freq, freq_lowerBound);

      for (int k = 0; k < std::min(lowerK, signal_freq.n); k++) {
          signal_freq.realPart[k] = 0;
          signal_freq.imPart[k] = 0;
      }

      int upperK = freqSampleNumber(signal_freq, freq_upperBound);

      for (int k = upperK; k < signal_freq.n; k++) {
          signal_freq.realPart[k] = 0;
          signal_freq.imPart[k] = 0;
      }

      sig::inverseFourierTransform(signal_freq, out_signal);
  }

  void bandStopFilter (const signal in_signal,
                       const freq freq_lowerBound,
                       const freq freq_upperBound,
                       signal& out_signal) {
      sig::signal_freqDomain signal_freq;
      sig::fourierTransform(in_signal, signal_freq);

      int lowerK = freqSampleNumber(signal_freq, freq_lowerBound);
      int upperK = freqSampleNumber(signal_freq, freq_upperBound);

      for (int k = lowerK; k < std::min(upperK, signal_freq.n); k++) {
          signal_freq.realPart[k] = 0;
          signal_freq.imPart[k] = 0;
      }

      sig::inverseFourierTransform(signal_freq, out_signal);
  }
}
