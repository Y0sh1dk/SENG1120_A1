#include "LinkedList.h"


LinkedList::LinkedList() {
    head = NULL;
    tail = NULL;
}

void LinkedList::addToHead(Node::value_type& item) {
    head = new Node(item, head, NULL);
    if (tail == NULL) {
        tail = head;
    }
}

void LinkedList::addToTail(Node::value_type& item) {
    if (tail == NULL) {
        Node* temp = new Node(item);
        head = temp;
        tail = temp;
        temp = NULL;
    } else { // atleast one node
       Node* temp = new Node(item);
       temp->set_prev(tail);
       tail->set_next(temp);
       tail = temp;
       temp = NULL; 
    }
}

void LinkedList::addToCurrent(Node::value_type&) {

}

Node::value_type LinkedList::removeFromHead() {

}
Node::value_type LinkedList::removeFromCurrent() {

}

void LinkedList::start() {
    current = head;
}

void LinkedList::end() {
    current = tail;
}

void LinkedList::forward() {
    current = current->get_next();
}

void LinkedList::back() {
    current = current->get_prev();
}

Node::value_type LinkedList::getCurrent() {

}

unsigned int LinkedList::count() {
    int a = 0;
    for (current = head; current != NULL; current = current->get_next()) {
        a++;
    }
    return a;
}

std::ostream& operator << (std::ostream& out, LinkedList& l) {

    // Do stuff
    return out;
}