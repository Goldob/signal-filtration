#include "filters.h"
#include "fourier.h"

namespace dsp {
    inline int freqSampleNumber(signal_freqDomain signal_freq, freq desired_freq) {
        return signal_freq.n * 2 * desired_freq / signal_freq.samplingFreq;
    }

    filter lowPassFilter (const freq freq_upperBound) {
        return [&](signal in_signal) -> signal {
            dsp::signal_freqDomain signal_freq;
            dsp::fourierTransform(in_signal, signal_freq);

            int upperK = freqSampleNumber(signal_freq, freq_upperBound);

            for (int k = upperK; k < signal_freq.n; k++) {
                signal_freq.realPart[k] = 0;
                signal_freq.imPart[k] = 0;
            }

            signal out_signal;
            dsp::inverseFourierTransform(signal_freq, out_signal);

            return out_signal;
        };
    }

    filter highPassFilter (const freq freq_lowerBound) {
        return [&](signal in_signal) -> signal {
            dsp::signal_freqDomain signal_freq;
            dsp::fourierTransform(in_signal, signal_freq);

            int lowerK = freqSampleNumber(signal_freq, freq_lowerBound);

            for (int k = 0; k < std::min(lowerK, signal_freq.n); k++) {
                signal_freq.realPart[k] = 0;
                signal_freq.imPart[k] = 0;
            }

            signal out_signal;
            dsp::inverseFourierTransform(signal_freq, out_signal);

            return out_signal;
        };
    }

    filter bandPassFilter (const freq freq_lowerBound,
                           const freq freq_upperBound) {
        return [&](signal in_signal) -> signal {
            dsp::signal_freqDomain signal_freq;
            dsp::fourierTransform(in_signal, signal_freq);

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

            signal out_signal;
            dsp::inverseFourierTransform(signal_freq, out_signal);

            return out_signal;
        };
    }

    filter bandStopFilter (const freq freq_lowerBound,
                           const freq freq_upperBound) {
        return [&](signal in_signal) -> signal {
            dsp::signal_freqDomain signal_freq;
            dsp::fourierTransform(in_signal, signal_freq);

            int lowerK = freqSampleNumber(signal_freq, freq_lowerBound);
            int upperK = freqSampleNumber(signal_freq, freq_upperBound);

            for (int k = lowerK; k < std::min(upperK, signal_freq.n); k++) {
                signal_freq.realPart[k] = 0;
                signal_freq.imPart[k] = 0;
            }

            signal out_signal;
            dsp::inverseFourierTransform(signal_freq, out_signal);

            return out_signal;
        };
    }
}
