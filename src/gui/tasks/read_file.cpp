#include "read_file.h"

ReadFileTask::ReadFileTask (QString fileName) {
    m_fileName = fileName;
}

void ReadFileTask::run () {
    dsp::signal output;

    try {
        dsp::readSignalFromFile(m_fileName.toStdString(), output);
        emit success (m_fileName, output);
    } catch (SignalIOException e) {
        QString errorMessage = "Błąd przy otwieraniu pliku ";
        errorMessage += m_fileName;
        errorMessage += ": \n";

        switch (e) {
            case STREAM_NOT_OPEN:
                errorMessage += "nie udało się otworzyć strumienia";
                break;
            case NONPOSITIVE_FREQ:
                errorMessage += "częstotliwość próbkowania musi być większa od zera";
                break;
            case NONPOSITIVE_SAMPLE_NUM:
                errorMessage += "ilość próbek musi być większa od zera";
                break;
            case PREMATURE_EOF:
                errorMessage += "przedwczesny koniec pliku";
                break;
            default:
                errorMessage += "wystąpił nieznany błąd";
                break;
        }

        emit failure(errorMessage);
    }
}
