#define READ_INPUT(var, desc, cond, err) while(true) { \
    wcout << desc << ": "; \
    cin >> var; \
    if (cond) break; \
    cout << err << endl; \
}

#define DESC_IN_FILENAME "Sciezka pliku wejsciowego"
#define DESC_OUT_FILENAME "Sciezka pliku wyjsciowego"
#define DESC_FILTER_TYPE "Rodzaj filtra (lp, hp, bp, bs)"
#define DESC_UPPER_BOUND "Dolna granica czestotliwosci [Hz]"
#define DESC_LOWER_BOUND "Gorna granica czestotliwosci [Hz]"

#define ERR_INVALID_FILTER "Niepoprawny rodzaj filtra!"
#define ERR_NONPOSITIVE_FREQ "Czestotliwosc musi byc wieksza od zera!"

#include <iostream>
#include <string>

#include "signal.h"
#include "filters.h"

using namespace std;

enum filter_type {
    UNDEFINED,
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
    else out_filterType = UNDEFINED;

    return out_filterType != UNDEFINED;
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

    sig::signal in_signal;
    sig::signal out_signal;

    // Wczytaj sygnał wejściowy z pliku
    sig::readSignalFromFile(in_fileName, in_signal);

    sig::freq freq_lowerBound;
    sig::freq freq_upperBound;

    // Wywołaj odpowiedni algorytm w zależności od wybranego filtra
    switch (filterType) {
    case LOW_PASS:
        READ_INPUT(freq_upperBound,
                   DESC_UPPER_BOUND,
                   freq_upperBound > 0,
                   ERR_NONPOSITIVE_FREQ);

        sig::lowPassFilter(in_signal,
                           freq_upperBound,
                           out_signal);
        break;
    case HIGH_PASS:
        READ_INPUT(freq_lowerBound,
                   DESC_UPPER_BOUND,
                   freq_lowerBound > 0,
                   ERR_NONPOSITIVE_FREQ);

        sig::highPassFilter(in_signal,
                            freq_lowerBound,
                            out_signal);
        break;
    case BAND_PASS:
        READ_INPUT(freq_lowerBound,
                   DESC_UPPER_BOUND,
                   freq_lowerBound > 0,
                   ERR_NONPOSITIVE_FREQ);

        READ_INPUT(freq_upperBound,
                   DESC_UPPER_BOUND,
                   freq_upperBound > 0,
                   ERR_NONPOSITIVE_FREQ);

        sig::bandPassFilter(in_signal,
                            freq_lowerBound,
                            freq_upperBound,
                            out_signal);
        break;
    case BAND_STOP:
        READ_INPUT(freq_lowerBound,
                   DESC_UPPER_BOUND,
                   freq_lowerBound > 0,
                   ERR_NONPOSITIVE_FREQ);

        READ_INPUT(freq_upperBound,
                   DESC_UPPER_BOUND,
                   freq_upperBound > 0,
                   ERR_NONPOSITIVE_FREQ);

        sig::bandStopFilter(in_signal,
                            freq_lowerBound,
                            freq_upperBound,
                            out_signal);
       break;
    }

    // Zapisz sygnał wyjściowy do pliku
    sig::saveSignalToFile(out_fileName, in_signal /* TODO out_signal */);
}
