
#include <iostream>

#include "node.cpp"
#include "binaryTree.cpp"

int main() {
    Tree<int>* tree = new Tree<int>();
    tree->insert(10);
    Node<int>* root = tree->getRoot();

    for (int i = 0; i < 10; ++i) {
        tree->insert(root, (i + 1) * 10);
    }

    std::cout << "Root is -> " << root->value << std::endl;

    std::cout << "Print level by level" << std::endl;
    tree->levelOrderPrint();
    tree->preOrderPrint(root);
    std::cout << std::endl;
    tree->postOrderPrint(root);
    std::cout << std::endl;
    tree->printWithStack();
    std::cout << std::endl;

    tree->remove(root, 100);

    std::cout << "*******************" << std::endl;
    std::cout << "Print In order" << std::endl;
    tree->inOrderPrint(root);
    std::cout << std::endl;

    delete tree;

    return 0;
}