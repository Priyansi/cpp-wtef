#include "../header_files/binary_search_tree.h"

template <typename DataType>
bool printAncestorNodes(Node<DataType>* root, DataType val) {
    if (root == nullptr) {
        return false;
    }
    if (root->data == val) {
        return true;
    }
    if (printAncestorNodes(root->left_child, val) || printAncestorNodes(root->right_child, val)) {
        cout << root->data << " ";
    }
}

int main(int argc, char* argv[]) {
    BinarySearchTree<int> b;
    b.insertNode(6);
    b.insertNode(4);
    b.insertNode(9);
    b.insertNode(5);
    b.insertNode(2);
    b.insertNode(8);
    b.insertNode(12);
    b.insertNode(10);
    b.insertNode(14);
    Node<int>* root = b.getRoot();
    printAncestorNodes(root, 10);
    return 0;
}