/* File filter_signal.h */
#ifndef FILTER_SIGNAL_INCLUDED
#define FILTER_SIGNAL_INCLUDED

#include "task.h"
#include "signal.h"

typedef std::function<dsp::signal (dsp::signal)> filter;

class FilterSignalTask : public Task {
    Q_OBJECT

    public:
        FilterSignalTask (dsp::signal input, filter _filter);
        void run ();

    private:
        dsp::signal m_input;
        filter m_filter;

    signals:
        void done (dsp::signal output);
};

#endif /* !FILTER_SIGNAL_INCLUDED */
