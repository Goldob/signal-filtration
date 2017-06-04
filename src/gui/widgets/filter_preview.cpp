#define INPUT_SIGNAL tr("Sygnał wejściowy")
#define OUTPUT_SIGNAL tr("Sygnał wyjściowy")

#define X_AXIS_LABEL tr("Czas [s]")
#define Y_AXIS_LABEL tr("Amplituda")

#include "filter_preview.h"

FilterPreview::FilterPreview (dsp::signal input, QWidget * parent) :
    QChartView(parent) {

    setChart(m_chart);

    encodeSignal(input, m_inputSeries);
    m_inputSeries->setName(INPUT_SIGNAL);
    m_inputSeries->setColor(Qt::lightGray);

    m_outputSeries->setName(OUTPUT_SIGNAL);

    m_chart->addSeries(m_inputSeries);
    m_chart->addSeries(m_outputSeries);
    m_chart->createDefaultAxes();
    m_chart->axisX()->setTitleText(X_AXIS_LABEL);
    m_chart->axisY()->setTitleText(Y_AXIS_LABEL);

    updateOutput(input);
    setRenderHint(QPainter::Antialiasing);
}

void FilterPreview::updateOutput (dsp::signal output) {
    encodeSignal(output, m_outputSeries);
}

void FilterPreview::encodeSignal (dsp::signal signal, QLineSeries * series) {
    series->clear();

    int sample_num = 0;
    signal.samples.forEach([&](dsp::sample s) {
        series->append((sample_num++)/signal.samplingFreq, s);
    });
}
