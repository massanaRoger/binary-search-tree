#ifndef CPP_BINARY_TREE_BINARYTREE_H
#define CPP_BINARY_TREE_BINARYTREE_H

#include <cstddef>

namespace binary_tree {

    struct Node {
        size_t value;
        Node* right;
        Node* left;
    };

    class BinaryTree {
    public:
        BinaryTree() = default;
        void Insert(size_t val);
        void Print();
        bool Search(size_t val);
    private:
        Node* m_root;
    };

}

#endif
