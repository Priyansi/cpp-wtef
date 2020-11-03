#include <iostream>

using namespace std;

template <typename DataType>
class Node {
   public:
    DataType data;
    Node<DataType>* left_child;
    Node<DataType>* right_child;
    Node() {
        left_child = right_child = nullptr;
    }
    Node(DataType val) {
        data = val;
        left_child = right_child = nullptr;
    }
};

template <typename DataType>
class BinarySearchTree {
    Node<DataType>* root;

   public:
    BinarySearchTree() {
        root = nullptr;
    }

    Node<DataType>* getRoot() {
        return root;
    }

    Node<DataType>* insertNodeRecr(Node<DataType>* root, DataType val) {
        if (root == nullptr) {
            root = new Node<DataType>(val);
        } else if (root->data > val) {
            root->left_child = insertNodeRecr(root->left_child, val);
        } else {
            root->right_child = insertNodeRecr(root->right_child, val);
        }
        return root;
    }

    void insertNode(DataType val) {
        root = insertNodeRecr(root, val);
    }

    bool searchRecr(Node<DataType>* root, DataType val) {
        if (root != nullptr) {
            if (root->data == val) {
                return true;
            } else if (root->data > val) {
                return searchRecr(root->left_child, val);
            } else {
                return searchRecr(root->right_child, val);
            }
        }
        return false;
    }

    bool search(DataType val) {
        return searchRecr(root, val);
    }

    Node<DataType>* getMaxSubTree(Node<DataType>* root) {
        if (root == nullptr || root->right_child == nullptr) {
            return root;
        }
        return getMaxSubTree(root->right_child);
    }

    Node<DataType>* getMinSubTree(Node<DataType>* root) {
        if (root == nullptr || root->left_child == nullptr) {
            return root;
        }
        return getMinSubTree(root->left_child);
    }

    Node<DataType>* getMaxTree() {
        return getMaxSubTree(root);
    }

    Node<DataType>* getMinTree() {
        return getMinSubTree(root);
    }

    Node<DataType>* deleteNodeRecr(Node<DataType>* root, DataType val) {
        if (root->data > val) {
            root->left_child = deleteNodeRecr(root->left_child, val);
        } else if (root->data < val) {
            root->right_child = deleteNodeRecr(root->right_child, val);
        } else {
            if (root->left_child != nullptr && root->right_child != nullptr) {
                Node<DataType>* left_tree_max = getMaxSubTree(root->left_child);
                root->data = left_tree_max->data;
                root->left_child = deleteNodeRecr(root->left_child, left_tree_max->data);
            } else if (root->left_child == nullptr && root->right_child == nullptr) {
                delete root;
                root = nullptr;
            } else {
                Node<DataType>* child_node;
                if (root->left_child != nullptr) {
                    child_node = root->left_child;
                } else {
                    child_node = root->right_child;
                }
                delete root;
                return child_node;
            }
        }
        return root;
    }

    void deleteNode(DataType val) {
        if (!search(val)) {
            cout << "Node not found.\n";
            return;
        }
        root = deleteNodeRecr(root, val);
    }

    void inorderTraverseRecr(Node<DataType>* root) {
        if (root == nullptr) {
            return;
        }
        inorderTraverseRecr(root->left_child);
        cout << root->data << " ";
        inorderTraverseRecr(root->right_child);
    }

    void inorderTraverse() {
        inorderTraverseRecr(root);
        cout << "\n";
    }

    void preorderTraverseRecr(Node<DataType>* root) {
        if (root == nullptr) {
            return;
        }
        cout << root->data << " ";
        preorderTraverseRecr(root->left_child);
        preorderTraverseRecr(root->right_child);
    }

    void preorderTraverse() {
        preorderTraverseRecr(root);
        cout << "\n";
    }

    void postorderTraverseRecr(Node<DataType>* root) {
        if (root == nullptr) {
            return;
        }
        postorderTraverseRecr(root->left_child);
        postorderTraverseRecr(root->right_child);
        cout << root->data << " ";
    }

    void postorderTraverse() {
        postorderTraverseRecr(root);
        cout << "\n";
    }
};

int main(int argc, char* argv[]) {
    BinarySearchTree<int> b;
    b.insertNode(4);
    b.insertNode(2);
    b.insertNode(3);
    b.insertNode(1);
    b.insertNode(6);
    b.insertNode(5);
    b.inorderTraverse();
    /*
    Output -
    1 2 3 4 5 6 
    */

    b.preorderTraverse();
    /*
    Output -
    4 2 1 3 6 5 
    */

    b.postorderTraverse();
    /*
    Output -
    1 3 2 5 6 4
    */

    cout << (b.search(3) ? "Node Found" : "Node Not Found") << "\n";
    /*
    Output -
    Node Found
    */

    cout << ((b.getMaxTree() != nullptr) ? to_string(b.getMaxTree()->data) : "") << "\n";
    /*
    Output -
    6
    */

    cout << ((b.getMinTree() != nullptr) ? to_string(b.getMinTree()->data) : "") << "\n";
    /*
    Output -
    1
    */

    b.deleteNode(2);  // two children
    b.inorderTraverse();
    /*
    Output -
    1 3 4 5 6 
    */

    b.deleteNode(6);  // one child
    b.inorderTraverse();
    /*
    Output -
    1 3 4 5 
    */

    b.deleteNode(5);  // no child
    b.inorderTraverse();
    /*
    Output -
    1 3 4 
    */

    return 0;
}
