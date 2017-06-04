#define SPACE ' '
#define BREAK '\n'

#include <string>
#include <sstream>
#include <fstream>

#include "signal.h"

namespace dsp {
    void readSignalFromFile (const std::string fileName,
                             signal& out_signal) {
        std::ifstream ifs(fileName.c_str());
        if (!ifs.is_open()) throw STREAM_NOT_OPEN;

        int n_samples;
        ifs >> out_signal.samplingFreq >> n_samples;

        if (out_signal.samplingFreq <= 0) throw NONPOSITIVE_FREQ;
        if (n_samples <= 0) throw NONPOSITIVE_SAMPLE_NUM;

        for (int i = 0; i < n_samples; i++) {
            sample tmp_sample;
            ifs >> tmp_sample;

            if (ifs.eof()) throw PREMATURE_EOF;

            out_signal.samples.push(tmp_sample);
        }
    }

    void saveSignalToFile (const std::string fileName,
                           const signal in_signal) {
        std::ostringstream strs;

        strs << in_signal.samplingFreq << SPACE
             << in_signal.samples.length() << BREAK;

        in_signal.samples.forEach([&strs](sample s) {
            strs << s << BREAK;
        });

        std::ofstream ofs(fileName.c_str());
        if (!ofs.is_open()) throw STREAM_NOT_OPEN;
        ofs << strs.str();
    }
}
