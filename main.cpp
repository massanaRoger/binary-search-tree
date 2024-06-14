#include <iostream>
#include "BinaryTree.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    binary_tree::BinaryTree tree{};
    tree.Insert(10);
    tree.Insert(3);
    tree.Insert(8);
    tree.Insert(16);
    tree.Print();
}
