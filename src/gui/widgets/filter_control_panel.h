/* File filter_control_panel.h */
#ifndef FILTER_CONTROL_PANEL_INCLUDED
#define FILTER_CONTROL_PANEL_INCLUDED

#define FILTER_TYPE_LABEL tr("Filtr:")
#define LOWER_BOUND_LABEL tr("od")
#define UPPER_BOUND_LABEL tr("do")
#define HERTZ_LABEL tr("Hz")

#define LOW_PASS_LABEL tr("dolnoprzepustowy")
#define HIGH_PASS_LABEL tr("górnoprzepustowy")
#define BAND_PASS_LABEL tr("środkowoprzepustowy")
#define BAND_STOP_LABEL tr("środkowozaporowy")

#define LOW_PASS_INDEX 0
#define HIGH_PASS_INDEX 1
#define BAND_PASS_INDEX 2
#define BAND_STOP_INDEX 3

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QDoubleSpinBox>
#include <functional>

#include "signal.h"
#include "filters.h"

/*!
 * \brief FilterControlPanel jest widgetem umożliwiającym wybór filtra i jego parametrów.
 */
class FilterControlPanel : public QWidget {
    Q_OBJECT

    public:
        /*!
         * \brief Tworzy nową instancję widgetu.
         */
        FilterControlPanel              (QWidget * parent = nullptr);

    public slots:
        /*!
         * \brief reset Przywraca domyślne ustawienia filtra i emituje sygnał \c filterSet.
         */
        void reset                      ();

    private slots:
        void onFilterTypeChanged        ();
        void onFilterParametersChanged  ();

    private:
        void toggleLowerBoundVisibility (bool visible);
        void toggleUpperBoundVisibility (bool visible);

        QHBoxLayout     * m_horizontalLayout        = new QHBoxLayout(this);
        QLabel          * m_filterTypeLabel         = new QLabel(FILTER_TYPE_LABEL);
        QComboBox       * m_filterTypeCombo         = new QComboBox();
        QLabel          * m_lowerBoundLabel         = new QLabel(LOWER_BOUND_LABEL);
        QDoubleSpinBox  * m_lowerBoundSpinBox       = new QDoubleSpinBox();
        QLabel          * m_lowerBoundHertzLabel    = new QLabel(HERTZ_LABEL);
        QLabel          * m_upperBoundLabel         = new QLabel(UPPER_BOUND_LABEL);
        QDoubleSpinBox  * m_upperBoundSpinBox       = new QDoubleSpinBox();
        QLabel          * m_upperBoundHertzLabel    = new QLabel(HERTZ_LABEL);

    signals:
        /*!
         * \brief Ten sygnał zostaje wyemitowany, gdy ustawienia filtra zmienią się.
         * \param filter Filtr do nałożenia na sygnał.
         */
        void filterSet                  (dsp::filter filter);
};

#endif /* !FILTER_CONTROL_PANEL_INCLUDED */
