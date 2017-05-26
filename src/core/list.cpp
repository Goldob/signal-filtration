#define NULL nullptr

#include "list.h"

namespace sig {
    template <class T> List<T>::List () {
        head = NULL;
        tail = NULL;
        counter = 0;
    }

    template <class T> void List<T>::push (T item) {
        Element * new_element = new Element(item, NULL);

        if (counter == 0) {
            head = new_element;
            tail = new_element;
        } else {
            tail->next = new_element;
            tail = new_element;
        }

        counter++;
    }

    template <class T> int List<T>::length () const {
        return counter;
    }

    template <class T> void List<T>::forEach (item_cb f) const {
        Element * current = head;
        while (current != NULL) {
            f(current->item);
            current = current->next;
        }
    }
}