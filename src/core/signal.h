/* File signal.h */
#ifndef SIGNAL_INCLUDED
#define SIGNAL_INCLUDED

#include <string>

#include "list.h"

namespace sig {
  typedef double freq;
  typedef double sample;

  struct signal {
    freq samplingFreq;
    List<sample> samples;
  };

  void readSignalFromFile (const std::string fileName,
                           signal& out_signal);
  
  void saveSignalToFile (const std::string fileName,
                         const signal in_signal);
}

#endif /* !SIGNAL_INCLUDED */
