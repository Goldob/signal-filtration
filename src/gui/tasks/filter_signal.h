/* File filter_signal.h */
#ifndef FILTER_SIGNAL_INCLUDED
#define FILTER_SIGNAL_INCLUDED

#include "task.h"
#include "signal.h"
#include "filters.h"

class FilterSignalTask : public Task {
    Q_OBJECT

    public:
        FilterSignalTask (dsp::signal input, dsp::filter filter);
        void run ();

    private:
        dsp::signal m_input;
        dsp::filter m_filter;

    signals:
        void done (dsp::signal output);
};

#endif /* !FILTER_SIGNAL_INCLUDED */
