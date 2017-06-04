#define READ_INPUT(var, desc, cond, err) while(true) { \
    wcout << desc << ": "; \
    cin >> var; \
    if (cond) break; \
    cout << err << endl; \
}

#define DESC_IN_FILENAME "Sciezka pliku wejsciowego"
#define DESC_OUT_FILENAME "Sciezka pliku wyjsciowego"
#define DESC_FILTER_TYPE "Rodzaj filtra (lp, hp, bp, bs)"
#define DESC_LOWER_BOUND "Dolna granica czestotliwosci [Hz]"
#define DESC_UPPER_BOUND "Gorna granica czestotliwosci [Hz]"

#define ERR_INVALID_FILTER "Niepoprawny rodzaj filtra!"
#define ERR_NONPOSITIVE_FREQ "Czestotliwosc musi byc wieksza od zera!"

#include <iostream>
#include <string>

#include "signal.h"
#include "filters.h"

using namespace std;

enum filter_type {
    LOW_PASS,
    HIGH_PASS,
    BAND_PASS,
    BAND_STOP
};

bool parseFilterCode (const string in_filterCode,
                      filter_type& out_filterType) {
    if (in_filterCode == "lp") out_filterType = LOW_PASS;
    else if (in_filterCode == "hp") out_filterType = HIGH_PASS;
    else if (in_filterCode == "bp") out_filterType = BAND_PASS;
    else if (in_filterCode == "bs") out_filterType = BAND_STOP;
    else return false;

    return true;
}

int main () {
    string in_fileName;
    string out_fileName;
    filter_type filterType;

    READ_INPUT(in_fileName, DESC_IN_FILENAME, true, NULL);
    READ_INPUT(out_fileName, DESC_OUT_FILENAME, true, NULL);

    string filterCode;
    READ_INPUT(filterCode,
               DESC_FILTER_TYPE,
               parseFilterCode(filterCode, filterType),
               ERR_INVALID_FILTER);

    dsp::signal in_signal;

    // Wczytaj sygnał wejściowy z pliku
    dsp::readSignalFromFile(in_fileName, in_signal);

    dsp::freq freq_lowerBound;
    dsp::freq freq_upperBound;

    dsp::filter myFilter;

    // Wczytaj odpowiednie parametry w zależności od wybranego filtra
    switch (filterType) {
    case LOW_PASS:
        READ_INPUT(freq_upperBound,
                   DESC_UPPER_BOUND,
                   freq_upperBound > 0,
                   ERR_NONPOSITIVE_FREQ);

        myFilter = dsp::lowPassFilter(freq_upperBound);
        break;
    case HIGH_PASS:
        READ_INPUT(freq_lowerBound,
                   DESC_UPPER_BOUND,
                   freq_lowerBound > 0,
                   ERR_NONPOSITIVE_FREQ);

        myFilter = dsp::highPassFilter(freq_lowerBound);
        break;
    case BAND_PASS:
        READ_INPUT(freq_lowerBound,
                   DESC_LOWER_BOUND,
                   freq_lowerBound > 0,
                   ERR_NONPOSITIVE_FREQ);

        READ_INPUT(freq_upperBound,
                   DESC_UPPER_BOUND,
                   freq_upperBound > 0,
                   ERR_NONPOSITIVE_FREQ);

        myFilter = dsp::bandPassFilter(freq_lowerBound,
                                       freq_upperBound);
        break;
    case BAND_STOP:
        READ_INPUT(freq_lowerBound,
                   DESC_LOWER_BOUND,
                   freq_lowerBound > 0,
                   ERR_NONPOSITIVE_FREQ);

        READ_INPUT(freq_upperBound,
                   DESC_UPPER_BOUND,
                   freq_upperBound > 0,
                   ERR_NONPOSITIVE_FREQ);

        myFilter = dsp::bandStopFilter(freq_lowerBound,
                                       freq_upperBound);
        break;
    }

    // Przeprowadź filtrację i zapisz sygnał wyjściowy do pliku
    dsp::saveSignalToFile(out_fileName, myFilter(in_signal));
}
