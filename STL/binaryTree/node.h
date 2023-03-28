#ifndef NODE_HPP
#define NODE_HPP

template <typename T>
struct Node {
        T value;
        Node<T>* left;
        Node<T>* right;
        ~Node();
        Node(T value  = 0);
        Node(Node<T>* &);
        Node<T>* operator=(Node<T>* other);
};

#endif