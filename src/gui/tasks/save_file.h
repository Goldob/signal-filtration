/* File save_file.h */
#ifndef SAVE_FILE_INCLUDED
#define SAVE_FILE_INCLUDED

#include "task.h"
#include "signal.h"

class SaveFileTask : public Task {
    Q_OBJECT

    public:
        SaveFileTask (QString fileName, dsp::signal input);
        void run ();

    private:
        QString m_fileName;
        dsp::signal m_input;

    signals:
        void success ();
        void failure (QString errorMessage);
};

#endif /* !SAVE_FILE_INCLUDED */
