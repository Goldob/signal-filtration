/* File signal.h */
#ifndef SIGNAL_INCLUDED
#define SIGNAL_INCLUDED

#include <string>

namespace sig {
  typedef double freq;

  struct signal {
    freq samplingFreq;
    int samplesNum;
    double * samples;
  };

  void readSignalFromFile (const std::string fileName,
                           signal& out_signal);
  
  void saveSignalToFile (const std::string fileName,
                         const signal in_signal);
}

#endif /* !SIGNAL_INCLUDED */
