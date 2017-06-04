#include <QHBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QDoubleSpinBox>

#include "filter_control_panel.h"

FilterControlPanel::FilterControlPanel (QWidget * parent) :
    QWidget(parent) {

    setLayout(m_horizontalLayout);
    m_horizontalLayout->setAlignment(Qt::AlignLeft);

    m_filterTypeCombo->addItem(LOW_PASS_LABEL);
    m_filterTypeCombo->addItem(HIGH_PASS_LABEL);
    m_filterTypeCombo->addItem(BAND_PASS_LABEL);
    m_filterTypeCombo->addItem(BAND_STOP_LABEL);

    connect(m_filterTypeCombo, SIGNAL(currentIndexChanged (int)),
            this, SLOT(onFilterTypeChanged ()));

    connect(m_lowerBoundSpinBox, SIGNAL(valueChanged (double)),
            this, SLOT(onFilterParametersChanged ()));

    connect(m_upperBoundSpinBox, SIGNAL(valueChanged (double)),
            this, SLOT(onFilterParametersChanged ()));

    m_horizontalLayout->addWidget(m_filterTypeLabel);
    m_horizontalLayout->addWidget(m_filterTypeCombo);
    m_horizontalLayout->addWidget(m_lowerBoundLabel);
    m_horizontalLayout->addWidget(m_lowerBoundSpinBox);
    m_horizontalLayout->addWidget(m_lowerBoundHertzLabel);
    m_horizontalLayout->addWidget(m_upperBoundLabel);
    m_horizontalLayout->addWidget(m_upperBoundSpinBox);
    m_horizontalLayout->addWidget(m_upperBoundHertzLabel);

    onFilterTypeChanged();
}

void FilterControlPanel::reset (dsp::signal input) {
    onFilterParametersChanged();
}

void FilterControlPanel::onFilterTypeChanged () {
    int typeIndex = m_filterTypeCombo->currentIndex();

    switch (typeIndex) {
        case LOW_PASS_INDEX:
            toggleLowerBoundVisibility(false);
            toggleUpperBoundVisibility(true);
            break;
        case HIGH_PASS_INDEX:
            toggleLowerBoundVisibility(true);
            toggleUpperBoundVisibility(false);
            break;
        case BAND_PASS_INDEX:
            toggleLowerBoundVisibility(true);
            toggleUpperBoundVisibility(true);
            break;
        case BAND_STOP_INDEX:
            toggleLowerBoundVisibility(true);
            toggleUpperBoundVisibility(true);
            break;
    }

    onFilterParametersChanged();
}

void FilterControlPanel::toggleLowerBoundVisibility (bool visible) {
    bool hidden = !visible;

    m_lowerBoundLabel->setHidden(hidden);
    m_lowerBoundSpinBox->setHidden(hidden);
    m_lowerBoundHertzLabel->setHidden(hidden);
}

void FilterControlPanel::toggleUpperBoundVisibility (bool visible) {
    bool hidden = !visible;

    m_upperBoundLabel->setHidden(hidden);
    m_upperBoundSpinBox->setHidden(hidden);
    m_upperBoundHertzLabel->setHidden(hidden);
}

void FilterControlPanel::onFilterParametersChanged () {
    dsp::filter filter;

    int typeIndex = m_filterTypeCombo->currentIndex();

    dsp::freq freq_lowerBound = m_lowerBoundSpinBox->value();
    dsp::freq freq_upperBound = m_upperBoundSpinBox->value();

    switch (typeIndex) {
        case LOW_PASS_INDEX:
            filter = dsp::lowPassFilter(freq_upperBound);
            break;
        case HIGH_PASS_INDEX:
            filter = dsp::highPassFilter(freq_lowerBound);
            break;
        case BAND_PASS_INDEX:
            filter = dsp::bandPassFilter(freq_lowerBound,
                                         freq_upperBound);
            break;
        case BAND_STOP_INDEX:
            filter = dsp::bandStopFilter(freq_lowerBound,
                                         freq_upperBound);
            break;
    }

    emit filterSet(filter);
}
