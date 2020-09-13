
#include "Node.h"


Node::Node(value_type d, Node* n = NULL, Node* p = NULL) {
    data = d;
    next = n;
    prev = p;

}

Node::value_type Node::get_data() const {
    return data;
}

void Node::set_data(const Node::value_type givenData) {
    data = givenData;
}

Node* Node::get_next() {
    return next;
}
void Node::set_next(Node* n) {
    next = n;
}

Node* Node::get_prev() {
    return prev;
}

void Node::set_prev(Node* n) {
    prev = n;
}