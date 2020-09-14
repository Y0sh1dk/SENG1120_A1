#include "LinkedList.h"


LinkedList::LinkedList() {
    current = NULL;
    head = NULL;
    tail = NULL;
}

LinkedList::~LinkedList() {
    // Do stuff
}

void LinkedList::addToHead(value_type& item) {
    head = new Node(item, head, NULL);
    if (tail == NULL) {
        tail = head;
    }
}

void LinkedList::addToTail(value_type& item) {
    if (tail == NULL) {
        Node* temp = new Node(item);
        head = temp;
        tail = temp;
        temp = NULL;
    } else { // atleast one node
       Node* temp = new Node(item);
       temp->setPrev(tail);
       tail->setNext(temp);
       tail = temp;
       temp = NULL; 
    }
}

void LinkedList::addToCurrent(value_type& item) {
    Node* n = new Node(item);
    n->setNext(current);
    n->setPrev(current->getPrev());
    current->setPrev(n);
    n->getPrev()->setNext(n);
    current = head;
}

void LinkedList::removeHead() {
    head = head->getNext();
    delete(head->getPrev());
    head->setPrev(NULL);
}

void LinkedList::removeTail() {
    tail = tail->getPrev();
    delete(tail->getNext());
    tail->setNext(NULL);
}


void LinkedList::removeCurrent() {

}

void LinkedList::add(LinkedList::value_type s) {

}

void LinkedList::remove(value_type s) {

}

void LinkedList::sort() {

}

// void LinkedList::start() {
//     current = head;
// }

// void LinkedList::end() {
//     current = tail;
// }

// void LinkedList::forward() {
//     current = current->getNext();
// }

// void LinkedList::back() {
//     current = current->getPrev();
// }

LinkedList::value_type LinkedList::getCurrent() {
    return current->getData();
}

LinkedList::value_type LinkedList::getHead() {
    return head->getData();
}

LinkedList::value_type LinkedList::getTail() {
    return tail->getData();
}

unsigned int LinkedList::size() {
    int a = 0;
    for (current = head; current != NULL; current = current->getNext()) {
        a++;
    }
    return a;
}

unsigned int LinkedList::count(LinkedList::value_type s) {
    // Count occurances of string
    return 0;
}

std::ostream& operator << (std::ostream& out, LinkedList& l) {

    // Do stuff
    return out;
}

void LinkedList::operator+= (LinkedList&) {

}