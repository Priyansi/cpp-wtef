#include "../header_files/binary_search_tree.h"

template <typename DataType>
int findHeight(Node<DataType>* root) {
    if (root == nullptr) {
        return 0;
    }
    return max(findHeight(root->left_child), findHeight(root->right_child)) + 1;
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
    cout << findHeight(root) << "\n";
    return 0;
}