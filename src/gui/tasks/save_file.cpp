#include "save_file.h"

SaveFileTask::SaveFileTask (QString fileName, dsp::signal input) {
    m_fileName = fileName;
    m_input = input;
}

void SaveFileTask::run () {
    // TODO Handle i/o errors
    dsp::saveSignalToFile(m_fileName.toStdString(), m_input);

    emit success();
}
