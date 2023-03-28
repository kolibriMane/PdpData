#include <iostream>
#include <queue>
#include <stack>

#include "binaryTree.h"

template <typename T>
Tree<T>::Tree(): root(NULL) {
}

template <typename T>
Tree<T>::~Tree() {
}

/* Insert only for root */
template <typename T>
void Tree<T>::insert(T value) {
    if (!root) {
        root = new Node<T>(value);
    }
}

/* Insert element with queue */
template <typename T>
void Tree<T>::insert(Node<T>* root, int value) {
    if (NULL == this->root) {
        insert(value);
    } else if (!isNodeExists(root, value)) {
        std::queue<Node<T>*> queue;
        queue.push(root);
        while (!queue.empty()) {
            Node<T>* temp = queue.front();
            queue.pop();
            if (!temp->left) {
                temp->left = new Node<T>(value);
                break;
            } else {
                queue.push(temp->left);
            }

            if (!temp->right) {
                temp->right = new Node<T>(value);
                break;
            } else {
                queue.push(temp->right);
            }
        }
    }
}

/* Check is value exists recursive way */
template <typename T>
bool Tree<T>::isNodeExists(Node<T>* node, int value) {
    /* If tree is empty or head node is empty, element doesn't exist */
    if (node == NULL) {
        return false;
    }

    /* If current node value is equal value => node exists */
    if (node->value == value) {
        return true;
    }

    /* If node exists in left side */
    if (isNodeExists(node->left, value)) {
        return true;
    }

    /* If node exists in right side */
    if (isNodeExists(node->right, value)) {
        return true;
    }

    return false;
}

template <typename T>
void Tree<T>::levelOrderPrint() {
    /* If root is not NULL */
    if (NULL != root) {
        /* Create queue for level elements */
        std::queue<Node<T>*> queue;
        queue.push(root);

        /* Pop current level elements from queue and push current's left and right */
        while (!queue.empty()) {
            Node<T>* node = queue.front();
            std::cout << node->value << " ";
            queue.pop();

            if (node->left) {
                queue.push(node->left);
            }

            if (node->right) {
                queue.push(node->right);
            }
        }

        std::cout << std::endl;
    }
}

/* Show tree */
template <typename T>
void Tree<T>::inOrderPrint(Node<T>* current) {
    if (current) {
        inOrderPrint(current->left);
        std::cout << current->value << " ";
        inOrderPrint(current->right);
    }
}

/* Show tree */
template <typename T>
void Tree<T>::postOrderPrint(Node<T>* current) {
    if (current) {
        inOrderPrint(current->left);
        inOrderPrint(current->right);
        std::cout << current->value << " ";
    }
}

/* Show tree */
template <typename T>
void Tree<T>::preOrderPrint(Node<T>* current) {
    if (current) {
        std::cout << current->value << " ";
        inOrderPrint(current->left);
        inOrderPrint(current->right);
    }
}

/* Get root element of tree */
template <typename T>
Node<T>* Tree<T>::getRoot() {
    return root;
}

/* Get minimum value under that node */
template <typename T>
Node<T>* Tree<T>::minValueNode(Node<T>* node) {
    Node<T>* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }

    return current;
}

/* Remove node recursive way */
template <typename T>
Node<T>* Tree<T>::remove(Node<T>* node, T value) {
    if (node == NULL) {
        return NULL;
    }

    /*
    * If node has 2 childs
    * If node is less then current
    * If node is great then current
    * If node has right child
    * If node has left child
    */
    if (node->left != NULL && node->right != NULL) {
        Node<T>* temp = minValueNode(node->right);
        node->value = temp->value;
        node->right = remove(node->right, node->value);
    } else if (value < node->value) {
        node->left = remove(node->left, value);
    } else if (value > node->value) {
        node->right = remove(node->right, value);
    } else if (node->left == NULL) {
        return node->left;
    } else if (node->right == NULL) {
        return node->left;
    }

    return node;
}

/* In order print tree with stack */
template <typename T>
void Tree<T>::printWithStack() {
    /* If root is not NULL */
    std::stack<Node<T>*> stack;
    Node<T>* node = this->root;

    while (node != NULL || !stack.empty()) {
        while (node !=  NULL) {
            stack.push(node);
            node = node->left;
        }

        node = stack.top();
        stack.pop();
        std::cout << node->value << " ";
        node = node->right;
    }
}