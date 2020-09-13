#include <string>

#ifndef MY_NODE
#define MY_NODE

class Node {
    public:
        typedef string value_type;

        // COnstructors
        Node(value_type data, Node* p = NULL, Node* n = NULL);



        void set_data(const value_type givenData);
        value_type get_data() const;

        Node* get_next();
        void set_next(Node* n);

        Node* get_prev();
        void set_prev(Node* n);


    private:
        value_type data;
        Node* next;
        Node* prev;
};





#endif