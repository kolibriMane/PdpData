#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "node.h"

template <typename T>
class Tree {
    public:
        Tree();
        ~Tree();
        void insert(T value);
        Node<T>* remove(Node<T>*, T);
        void levelOrderPrint();
        void inOrderPrint(Node<T>*);
        Node<T>* getRoot();
        Node<T>* minValueNode(Node<T>*);
        void postOrderPrint(Node<T>*);
        void preOrderPrint(Node<T>*);
        void printWithStack();

        void insert(Node<T>*, int);
        bool isNodeExists(Node<T>*, int);

    private:
        Node<T>* root;
};

#endif