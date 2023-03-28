#ifndef NODE_HPP
#define NODE_HPP

template<typename T>
class Node {
    private:
        T value;
        Node<T>* next;
    public:
        T getValue();
        Node<T>* getNext();
        void setValue(T);
        void setNext(Node*);
        void show();
        Node(T value = 0);
        Node(T, Node<T>*);
        Node(Node<T>* &);
        ~Node();
};

#endif