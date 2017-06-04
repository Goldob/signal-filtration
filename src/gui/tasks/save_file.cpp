#include "save_file.h"

SaveFileTask::SaveFileTask (QString fileName, dsp::signal input) {
    m_fileName = fileName;
    m_input = input;
}

void SaveFileTask::run () {
    try {
        dsp::saveSignalToFile(m_fileName.toStdString(), m_input);
        emit success(m_fileName);
    } catch (SignalIOException e) {
        QString errorMessage = "Błąd przy zapisywaniu pliku ";
        errorMessage += m_fileName;
        errorMessage += ": \n";

        switch (e) {
            case STREAM_NOT_OPEN:
                errorMessage += "nie udało się otworzyć strumienia";
                break;
            default:
                errorMessage += "wystąpił nieznany błąd";
                break;
        }

        emit failure(errorMessage);
    }
}
