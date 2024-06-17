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
        printHelper(m_root, 0);
    }

    void BinaryTree::printHelper(Node* root, int space) {
        int COUNT = 10;
        if (root == nullptr)
            return;

        space += COUNT;

        printHelper(root->right, space);

        std::cout << std::endl;
        for (int i = COUNT; i < space; i++)
            std::cout << " ";
        std::cout << root->value << "\n";

        printHelper(root->left, space);
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

    Node* BinaryTree::findLowestNode(Node* node) {
        if (node == nullptr)
            return nullptr;
        while (node->left) {
            node = node->left;
        }

        return node;
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
                    nodeToDelete = node;
                break;
            }
        }
        if (!nodeToDelete->left && !nodeToDelete->right) {
            if (node->left == nodeToDelete) {
                delete node->left;
                node->left = nullptr;
            } else {
                delete node->right;
                node->right = nullptr;
            }
            return true;
        }
        if (!nodeToDelete->left && nodeToDelete->right) {
            if (node->left == nodeToDelete) {
                Node* nodeToReplace = node->left->right;
                delete node->left;
                node->left = nodeToReplace;
            } else {
                Node* nodeToReplace = node->right->right;
                delete node->right;
                node->right = nodeToReplace;
            }
            return true;
        }
        if (nodeToDelete->left && !nodeToDelete->right) {
            if (node->left == nodeToDelete) {
                Node* nodeToReplace = node->left->left;
                delete node->left;
                node->left = nodeToReplace;
            } else {
                Node* nodeToReplace = node->right->left;
                delete node->right;
                node->right = nodeToReplace;
            }
            return true;
        }

        if (node->left == nodeToDelete) {
            Node* lowestNode = findLowestNode(node->left);
            delete node->left;
            node->left = lowestNode;
        } else {
            Node* lowestNode = findLowestNode(node->right);
            delete node->right;
            node->right = lowestNode;
        }

        return true;
    }

}
