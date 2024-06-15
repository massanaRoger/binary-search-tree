#include <iostream>
#include "BinaryTree.h"

namespace binary_tree {
    void BinaryTree::Insert(size_t val) {
        Node* node = m_root;

        if (m_root == nullptr) {
            Node* nodeToInsert = new Node{val, nullptr, nullptr};
            m_root = nodeToInsert;
            return;
        }
        while(true) {
            if (val < node->value) {
                if (node->left == nullptr) {
                    Node* nodeToInsert = new Node{val, nullptr, nullptr};
                    node->left = nodeToInsert;
                    return;
                } else {
                    node = node->left;
                }
            } else if (val > node->value) {
                if (node->right == nullptr) {
                    Node* nodeToInsert = new Node{val, nullptr, nullptr};
                    node->right = nodeToInsert;
                    return;
                } else {
                    node = node->right;
                }
            } else {
                return;
            }
        }
    }

    void BinaryTree::Print() {
        std::cout << m_root->value << std::endl;
    }

    bool BinaryTree::Search(size_t val) {
        Node* node = m_root;
        while (true) {
            if (val < node->value) {
                if (node->left == nullptr) {
                    return false;
                } else if (node->left->value == val) {
                    return true;
                } else {
                    node = node->left;
                }
            } else if (val > node->value) {
                if (node->right == nullptr) {
                    return false;
                } else if (node->right->value == val) {
                    return true;
                } else {
                    node = node->right;
                }
            }
        }
    }

}