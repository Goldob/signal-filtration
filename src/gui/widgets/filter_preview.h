/* File filter_preview.h */
#ifndef FILTER_PREVIEW_INCLUDED
#define FILTER_PREVIEW_INCLUDED

#include <QtCharts>

#include "signal.h"

/*!
 * \brief Klasa FilterPreview jest widgetem wyświetlającym podgląd sygnału w formie wykresu.
 */
class FilterPreview : public QChartView {
    Q_OBJECT

    public:
        /*!
         * \brief Tworzy nową instancję widgetu przypisaną do sygnału wejściowego (\a input).
         * \param input Sygnał wejściowy
         * \param parent
         */
        FilterPreview       (dsp::signal input, QWidget * parent = nullptr);

    public slots:
        /*!
         * \brief Aktualizuje wykres sygnału wyjściowego.
         * \param output Sygnał wyjściowy po nałożeniu filtra.
         */
        void updateOutput   (dsp::signal output);

    private:
        void encodeSignal   (dsp::signal _signal, QLineSeries * series);

        QChart      *   m_chart         = new QChart();
        QLineSeries *   m_inputSeries   = new QLineSeries();
        QLineSeries *   m_outputSeries  = new QLineSeries();
};

#endif /* !FILTER_PREVIEW_INCLUDED */
