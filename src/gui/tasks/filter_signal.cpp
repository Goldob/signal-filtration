#include "filter_signal.h"

FilterSignalTask::FilterSignalTask (dsp::signal input, filter _filter) {
    m_input = input;
    m_filter = _filter;
}

void FilterSignalTask::run () {
    dsp::signal output = m_filter(m_input);
    emit done(output);
}
