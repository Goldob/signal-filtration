#include <math.h>

#include "fourier.h"

namespace sig {
    inline double basisSin (int i, int k, int N) {
        return std::sin(2 * M_PI * k * i / N);
    }

    inline double basisCos (int i, int k, int N) {
        return std::cos(2 * M_PI * k * i / N);
    }

    void fourierTransform (const signal in_signal,
                           signal_freqDomain& out_signal) {
        out_signal.samplingFreq = in_signal.samplingFreq;
        int n_samples = in_signal.samples.length();
        out_signal.n = n_samples / 2;

        // Zapobiegamy wyciekowi pamięci, jeśli out_signal został już zainicjalizowany
        delete out_signal.realPart;
        delete out_signal.imPart;

        out_signal.realPart = new double[out_signal.n];
        out_signal.imPart   = new double[out_signal.n];

        for (int k = 0; k < out_signal.n; k++) {
            double realPart = 0.0, imPart = 0.0;

            int i = 0;
            in_signal.samples.forEach([&](sample s) {
                realPart    += s * basisCos(i, k, n_samples);
                imPart      -= s * basisSin(i, k, n_samples);
                i++;
            });

            out_signal.realPart[k] = realPart;
            out_signal.imPart[k] = imPart;
        }
    }

    void inverseFourierTransform (const signal_freqDomain in_signal,
                                  signal& out_signal) {
        out_signal.samplingFreq = in_signal.samplingFreq;
        int n_samples = in_signal.n * 2;

        // TODO clear out_signal.samples

        for (int i = 0; i < n_samples; i++) {
            sample tmp_sample = 0.0;

            for (int k = 0; k < in_signal.n; k++) {
                double scalingFactor = 2.0 / n_samples;

                double scaled_realPart  = in_signal.realPart[k] * scalingFactor;
                double scaled_imPart    = in_signal.imPart[k] * scalingFactor;

                if (k == 0 || k == in_signal.n - 1)
                    scaled_realPart = scaled_realPart / 2;

                tmp_sample += scaled_realPart   * basisCos(i, k, n_samples);
                tmp_sample -= scaled_imPart     * basisSin(i, k, n_samples);
            }

            out_signal.samples.push(tmp_sample);
        }
    }
}
