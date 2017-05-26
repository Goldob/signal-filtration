#ifndef LIST_INCLUDED
#define LIST_INCLUDED

#include <functional>

namespace dsp {
    /*!
     * \brief Generyczna klasa listy jednokierunkowej.
     */
    template <class T> class List {
        /*!
         * \brief Funkcja do wywołania zwrotnego (z ang. \e callback)
         *        na wszystkich elemetach listy w poszczególnych iteracjach pętli forEach.
         */
        typedef std::function<void (T)> item_cb;

        //! Wewnętrzna struktura, reprezentująca poszczególne elementy listy.
        private: struct Element {
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
            void push (T);                  //!< \brief Dodaj nowy element na koniec listy.
            int length () const;            //!< \brief Zwraca aktualną dlugosc listy.
            void forEach (item_cb) const;   //!< \brief Wywołaj funkcję na wszystkich elementach listy, zaczynając od jej początku.
    };

    template class List<double>;
}

#endif /* !SIGNAL_INCLUDED */
