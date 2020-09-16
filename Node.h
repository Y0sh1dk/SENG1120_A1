#include <string>

#ifndef MY_NODE
#define MY_NODE

class Node {
    public:
        typedef std::string value_type;

        // Constructors/destructor
        Node();
        Node(value_type data, Node* p = NULL, Node* n = NULL);
        ~Node();

        void setData(const value_type givenData);
        value_type getData() const;

        Node* getNext();
        void setNext(Node* n);

        Node* getPrev();
        void setPrev(Node* n);

    private:
        value_type data;
        Node* next;
        Node* prev;
};


#endif