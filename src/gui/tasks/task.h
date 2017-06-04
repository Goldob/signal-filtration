/* File task.h */
#ifndef TASK_INCLUDED
#define TASK_INCLUDED

#include <QObject>
#include <QRunnable>

/*!
 * \brief Klasa Task stanowi bazę dla tworzenia asynchronicznych zadań.
 *
 * Klasa Task dziedziczy z klas \c QObject oraz \c QRunnable. Pierwsza z nich pozwala
 * emitować sygnały, a druga konieczna jest do wykonywania zadań w sposób asynchroniczny,
 * za pomocą instancji klasy \c QThreadPool. W przeciwieństwie do \c QRunnable, Task ustala domyślną
 * wartość pola \c autoDelete na \c true. Ma to na celu uzyskanie większej elastyczności
 * przy manipulacji zadaniami.
 */
class Task : public QObject, public QRunnable {
    public:
        /*!
         * \brief Tworzy nową instancję zadania.
         */
        Task ();
};

#endif /* !TASK_INCLUDED */
