#include "read_file.h"

ReadFileTask::ReadFileTask (QString fileName) {
    m_fileName = fileName;
}

void ReadFileTask::run () {
    dsp::signal output;
    // TODO Handle i/o errors
    dsp::readSignalFromFile(m_fileName.toStdString(), output);

    emit success (m_fileName, output);
}
