#ifndef LIST_INCLUDED
#define LIST_INCLUDED

#include <functional>

namespace sig {
    template <class T> class List {
        typedef std::function<void (T)> item_cb;

        struct Element {
            T item;
            Element * next;

            Element (T item, Element * next) {
                this->item = item;
                this->next = next;
            }
        };

        private:
            Element * head;
            Element * tail;
            int counter;
        public:
            List();
            void push (T);
            int length () const;
            void forEach (item_cb) const;
    };

    template class List<double>;
}

#endif /* !SIGNAL_INCLUDED */
