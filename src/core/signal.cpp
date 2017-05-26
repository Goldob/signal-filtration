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

        int n_samples;
        ifs >> out_signal.samplingFreq >> n_samples;

        for (int i = 0; i < n_samples; i++) {
            sample tmp_sample;
            ifs >> tmp_sample;

            if (ifs.eof()) break; // TODO throw error

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
        ofs << strs.str();
    }
}
