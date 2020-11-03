#include "../header_files/binary_search_tree.h"
#include "../header_files/stack_arr.h"

template <typename DataType>
DataType findKthMax(Node<DataType>* root, int k, int nodes) {
    int count = nodes - k;
    Stack<Node<DataType>*> s(nodes);
    Node<DataType>* curr = root;
    Node<DataType>* deleted_node;
    while (curr != nullptr) {
        s.push(curr);
        curr = curr->left_child;
    }
    while (!s.isEmpty()) {
        curr = *(s.peek());
        s.pop();
        if (!(count--)) {
            return curr->data;
        }
        curr = curr->right_child;
        while (curr != nullptr) {
            s.push(curr);
            curr = curr->left_child;
        }
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
    Node<int>* root = b.getRoot();
    cout << findKthMax(root, 3, 6) << endl;
    return 0;
}