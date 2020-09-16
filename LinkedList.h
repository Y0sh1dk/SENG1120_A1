#include "Node.h"

#ifndef MY_LINKEDLIST
#define MY_LINKEDLIST

class LinkedList {
    public:
        typedef Node::value_type value_type;
        // Constructors/Destructors
        LinkedList();
        ~LinkedList();

        void add(value_type s);
        void remove(value_type s);
        void removeWord(value_type s);
        void removeSentence(value_type s);
        void sort();

        void addToHead(value_type&);
        void addToTail(value_type);
        void addAfterCurrent(value_type&);

        void removeHead();
        void removeTail();
        void removeCurrent();

        value_type getHead();
        value_type getTail();
        value_type getCurrent();

        void start();
        void end();
        void forward();
        void back();

        unsigned int count(value_type s);
        unsigned int size(); // can only be positive so unsigned

        void operator += (LinkedList& l2);

    private:
        Node* head;
        Node* tail;
        Node* current;

};

std::ostream& operator << (std::ostream& out, LinkedList& l);

#endif