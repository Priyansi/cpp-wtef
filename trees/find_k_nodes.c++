#include "../header_files/binary_search_tree.h"
#include "../header_files/queue_ll.h"

template <typename DataType>
void printKNodesIter(Node<DataType>* root, int k) {
    if (root != nullptr) {
        Queue<Node<DataType>*> q;
        Node<DataType>* curr_node;
        q.enqueue(root);
        while (k--) {
            curr_node = q.getFront()->data;
            q.dequeue();
            if (curr_node->left_child != nullptr) {
                q.enqueue(curr_node->left_child);
            }
            if (curr_node->right_child != nullptr) {
                q.enqueue(curr_node->right_child);
            }
        }
        while (!q.isEmpty()) {
            curr_node = q.getFront()->data;
            q.dequeue();
            cout << curr_node->data << " ";
        }
    }
}

template <typename DataType>
void printKNodesRecr(Node<DataType>* root, int k) {
    if (root == nullptr) {
        return;
    }
    if (k == 0) {
        cout << root->data << " ";
        return;
    } else {
        printKNodesRecr(root->left_child, k - 1);
        printKNodesRecr(root->right_child, k - 1);
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
    printKNodesIter(root, 2);
    return 0;
}