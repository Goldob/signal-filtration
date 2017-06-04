#include "filter_signal.h"
#include "filters.h"

FilterSignalTask::FilterSignalTask (dsp::signal input, dsp::filter filter) {
    m_input = input;
    m_filter = filter;
}

void FilterSignalTask::run () {
    dsp::signal output = m_filter(m_input);
    emit done(output);
}
