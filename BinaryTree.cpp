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

    Node* BinaryTree::Search(size_t val) {
        Node* node = m_root;
        while (true) {
            if (val < node->value) {
                if (node->left == nullptr) {
                    return nullptr;
                } else if (node->left->value == val) {
                    return node->left;
                } else {
                    node = node->left;
                }
            } else if (val > node->value) {
                if (node->right == nullptr) {
                    return nullptr;
                } else if (node->right->value == val) {
                    return node->right;
                } else {
                    node = node->right;
                }
            }
        }
    }

    bool BinaryTree::Delete(size_t val) {
        Node* node = m_root;
        Node* nodeToDelete = Search(val);
        if (nodeToDelete == nullptr) {
            return false;
        }
        while (true) {
            if (val < node->value) {
                if (node->left->value == val) {
                    nodeToDelete = node->left;
                    break;
                }
                node = node->left;
            } else if (val > node->value) {
                if (node->right->value == val) {
                    nodeToDelete = node->right;
                    break;
                }
                node = node->right;
            } else {
                break;
            }
        }
        if (!nodeToDelete->left && !nodeToDelete->right) {
            delete nodeToDelete;
            prevNode = nullptr;
            return true;
        } else if (prevNode->left && !prevNode->right) {
            Node* nodeToReplace = prevNode->left;
            delete prevNode;
            prevNode = nodeToReplace;
        } else if (prevNode->right && !prevNode->left) {
            Node* nodeToReplace = prevNode->right;
            delete prevNode;
            prevNode = nodeToReplace;
        } else {

        }


    }

}