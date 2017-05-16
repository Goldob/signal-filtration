#ifndef LIST_INCLUDED
#define LIST_INCLUDED

namespace sig {
    template <class T> class List {
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
            int length ();
            void forEach (void f(T));
    };

    template class List<double>;
}

#endif /* !SIGNAL_INCLUDED */
