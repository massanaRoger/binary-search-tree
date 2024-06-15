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
    std::cout << tree.Search(8) << std::endl;
    std::cout << tree.Search(2) << std::endl;
    std::cout << tree.Search(34) << std::endl;
    std::cout << tree.Search(54) << std::endl;
}
