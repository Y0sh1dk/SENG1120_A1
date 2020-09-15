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
    if (size() > 0) {
        start();
        while(1) {
            Node* next;
            if (current->getNext() != NULL) {
                next = current->getNext();
            } else {
                break;
            }
            delete current;
            current = next;
        }
    }
}

void LinkedList::addToHead(value_type& item) {
    Node* newNode = new Node(item, head, NULL);
    if (head != NULL) {
        head->setPrev(newNode);
    }
    head = newNode;
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

void LinkedList::addAfterCurrent(value_type& item) { // insert after 'current'
    if (current == NULL) { // cannot insert after a NULL
        return;
    }
    Node* newNode = new Node(item);
    if (current == tail) {
        tail = newNode;
    }
    newNode->setNext(current->getNext());
    current->setNext(newNode);
    newNode->setPrev(current);
    if (newNode->getNext() != NULL) {
        newNode->getNext()->setPrev(newNode);
    }
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
            std::string word = s.substr(pos+1, i-pos-1); // dont like using std::string, as it only works for strings then
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
    start();
    int s = size();
    bool ordered = false;
    while (!ordered) {
        start();
        bool order = true;
        for (int i = 0; i < s-1; i++) {
            std::string currentString = getCurrent();
            forward();
            std::string nextString = getCurrent();

//        Find smallest word
            int minWordSize = 0;
            if (currentString.length() > nextString.length()) {
                minWordSize = nextString.length();
            } else if (currentString.length() < nextString.length()) {
                minWordSize = currentString.length();
            } else { // same size
                minWordSize = currentString.length();
            }

            for (int i = 0; i < minWordSize; i++) {
                if (currentString.at(i) > nextString.at(i)) {
//                swap two nodes
                    std::string temp = current->getData();
                    removeCurrent();
                    addToHead(temp);
                    order = false;
                    break;
                } else if (currentString.at(i) < nextString.at(i)) {
                    break;
                }
            }
        }
        if (order) {
            ordered = true;
        }
    }
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