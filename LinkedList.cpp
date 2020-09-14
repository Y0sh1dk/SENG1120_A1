#include <iostream>
#include <cstdlib>
#include <string>

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
        start();
        temp = NULL;
    } else { // atleast one node
       Node* temp = new Node(item);
       tail->setNext(temp);
       temp->setPrev(tail);
       tail = temp;
       start();
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
    if (current != tail) {
        current->getPrev()->setNext(current->getNext());
        current->getNext()->setPrev(current->getPrev());
        delete current;
        start();
    } else {
        current->getPrev()->setNext(NULL);
        delete current;
        start();
    }

}

void LinkedList::add(LinkedList::value_type s) {
    int pos = -1;
    for (unsigned long int i = 0; i <= s.length(); i++) {
        if (isspace(s[i])) {
            std::string word = s.substr(pos+1, i-pos-1);
            // std::cout << word << std::endl;
            pos = i;
            addToTail(word);
        }
    }
    std::string lastWord =  s.substr(pos+1, s.length());
    addToTail(lastWord);
}

void LinkedList::remove(value_type s) {
    start();
    while (current != NULL) { // runs through till hits end
        if (getCurrent() == s) {
            removeCurrent();
            start();
        }
        forward();
    }

}

void LinkedList::sort() {

}

void LinkedList::start() {
    current = head;
}

void LinkedList::end() {
    current = tail;
}

void LinkedList::forward() {
    current = current->getNext();
}

void LinkedList::back() {
    current = current->getPrev();
}

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
    start();
    return a;
}

unsigned int LinkedList::count(LinkedList::value_type s) {
    start();
    int a = 0;
    while (current != NULL) {
        if (getCurrent() == s) {
            a++;
        }
        forward();
    }
    return a;
}

std::ostream& operator << (std::ostream& out, LinkedList& l) {
    l.start(); // set current pointer to head
    std::string sentence;
    int size = l.size();
    for (int i = 0; i < size; i++) {
        sentence += l.getCurrent();
        sentence += " ";
        l.forward();
    }
    out << sentence;
    return out;
}

void LinkedList::operator+= (LinkedList& l2) {
    l2.start();
    int l2size = l2.size();
    for (int i = 0; i < l2size; i++) {
        std::string temp = l2.getCurrent();
        addToTail(temp);
        l2.forward();
    }
}