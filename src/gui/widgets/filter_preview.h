/* File filter_preview.h */
#ifndef FILTER_PREVIEW_INCLUDED
#define FILTER_PREVIEW_INCLUDED

#include <QtCharts>

#include "signal.h"

class FilterPreview : public QChartView {
    Q_OBJECT

    public:
        FilterPreview       (dsp::signal input, QWidget * parent = nullptr);

    public slots:
        void updateOutput   (dsp::signal output);

    private:
        void encodeSignal   (dsp::signal _signal, QLineSeries * series);

        QChart      *   m_chart         = new QChart();
        QLineSeries *   m_inputSeries   = new QLineSeries();
        QLineSeries *   m_outputSeries  = new QLineSeries();
};

#endif /* !FILTER_PREVIEW_INCLUDED */
