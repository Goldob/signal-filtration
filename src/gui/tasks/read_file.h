/* File read_file.h */
#ifndef READ_FILE_INCLUDED
#define READ_FILE_INCLUDED

#include "task.h"
#include "signal.h"

class ReadFileTask : public Task {
    Q_OBJECT

    public:
        ReadFileTask (QString fileName);
        void run ();

    private:
        QString m_fileName;

    signals:
        void success (QString fileName, dsp::signal output);
        void failure (QString errorMessage);
};

#endif /* !READ_FILE_INCLUDED */
