#ifndef NODE_HPP
#define NODE_HPP
class Node {
    private:
        int value;
        Node* next;
    public:
        int getValue();
        Node* getNext();
        void setValue(int);
        void setNext(Node*);
        void show();
        Node(int value = 0);
        Node(int, Node*);
        Node(Node* &);
        ~Node();
};

#endif