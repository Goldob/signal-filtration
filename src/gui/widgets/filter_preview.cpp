#define INPUT_SIGNAL tr("Sygnał wejściowy")
#define OUTPUT_SIGNAL tr("Sygnał wyjściowy")

#include "filter_preview.h"

FilterPreview::FilterPreview (dsp::signal input, QWidget * parent) :
    QChartView(parent) {

    setChart(m_chart);

    encodeSignal(input, m_inputSeries);
    m_inputSeries->setName(INPUT_SIGNAL);
    m_inputSeries->setColor(Qt::lightGray);

    encodeSignal(input, m_outputSeries);
    m_outputSeries->setName(OUTPUT_SIGNAL);

    m_chart->addSeries(m_inputSeries);
    m_chart->addSeries(m_outputSeries);

    updateOutput(input);
    setRenderHint(QPainter::Antialiasing);
}

FilterPreview::~FilterPreview () {
    delete m_chart;
    delete m_inputSeries;
    delete m_outputSeries;
}

void FilterPreview::showLoading () {
    // TODO
}

void FilterPreview::hideLoading () {
    // TODO
}

void FilterPreview::updateOutput (dsp::signal output) {
    encodeSignal(output, m_outputSeries);
}

void FilterPreview::encodeSignal (dsp::signal signal, QLineSeries * series) {
    series->clear();

    int sample_num = 0;
    signal.samples.forEach([&](dsp::sample s) {
        series->append(sample_num++, s);
    });
}
