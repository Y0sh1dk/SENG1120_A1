#include "Node.h"

#ifndef MY_LINKEDLIST
#define MY_LINKEDLIST

class LinkedList {
    public:
        LinkedList();

        void addToHead(Node::value_type&);
        void addToTail(Node::value_type&);
        void addToCurrent(Node::value_type&);

        Node::value_type removeFromHead();
        Node::value_type removeFromTail();
        Node::value_type removeFromCurrent();

        void start();
        void end();
        void forward();
        void back();
        Node::value_type getCurrent();
        unsigned int count(); // can only be positive so unsigned
        void remove(string s);

        LinkedList& operator += (LinkedList& l2);


    private:
        Node* head;
        Node* tail;
        Node* current;

};

std::ostream& operator << (std::ostream& out, LinkedList& l);



#endif