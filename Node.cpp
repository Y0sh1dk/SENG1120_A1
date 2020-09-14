
#include "Node.h"

Node::Node() {
    data = ""; // string cannot be made null
    next = NULL;
    prev = NULL;
}

Node::Node(value_type d, Node* n, Node* p) {
    data = d;
    next = n;
    prev = p;
}

Node::~Node() {
    // TODO: stff

}

Node::value_type Node::getData() const {
    return data;
}

void Node::setData(const Node::value_type givenData) {
    data = givenData;
}

Node* Node::getNext() {
    return next;
}
void Node::setNext(Node* n) {
    next = n;
}

Node* Node::getPrev() {
    return prev;
}

void Node::setPrev(Node* n) {
    prev = n;
}