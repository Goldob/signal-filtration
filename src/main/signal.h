/* File signal.h */
#ifndef SIGNAL_INCLUDED
#define SIGNAL_INCLUDED

namespace signal {
  typedef double freq;

  struct signal {
    freq samplingFreq;
    int samplesNum;
    double * samples;
  };

  void readSignalFromFile(const string fileName,
			  signal& out_signal);
  
  void saveSignalToFile(const string fileName,
			const signal in_signal);
}

#endif /* !SIGNAL_INCLUDED */
