/* File task.h */
#ifndef TASK_INCLUDED
#define TASK_INCLUDED

#include <QObject>
#include <QRunnable>

class Task : public QObject, public QRunnable {
    public:
        Task ();
};

#endif /* !TASK_INCLUDED */
