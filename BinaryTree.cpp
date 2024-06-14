#include <iostream>
#include "BinaryTree.h"

namespace binary_tree {
    void BinaryTree::Insert(size_t val) {
        Node* node = m_root;
        Node* nodeToInsert = new Node{};
        nodeToInsert->value = val;
        nodeToInsert->right = nullptr;
        nodeToInsert->left = nullptr;
        if (m_root == nullptr) {
            m_root = nodeToInsert;
            return;
        }
        bool found = false;
        while(!found) {
            if (val < node->value) {
                if (node->left == nullptr) {
                    node->left = nodeToInsert;
                    found = true;
                } else {
                    node = node->left;
                }
            } else if (val > node->value) {
                if (node->right == nullptr) {
                    node->right = nodeToInsert;
                    found = true;
                } else {
                    node = node->right;
                }
            } else {
                found = true;
            }
        }
    }

    void BinaryTree::Print() {
        std::cout << m_root->value << std::endl;
    }
}