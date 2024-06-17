#include <iostream>
#include "BinaryTree.h"

int main() {
    binary_tree::BinaryTree tree{};
    tree.Insert(10);
    tree.Insert(3);
    tree.Insert(8);
    tree.Insert(16);
    tree.Insert(6);
    tree.Insert(34);
    tree.Insert(13);
    tree.Print();
    std::cout << "Next tree" << std::endl;
    tree.Delete(8);
    tree.Delete(6);
    tree.Delete(34);
    tree.Print();
}
