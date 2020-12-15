#include <iostream>

using namespace std;

template <typename DataType>
class Node {
   public:
    DataType weight;
    Node<DataType>* left_child;
    Node<DataType>* right_child;
    Node() {
        left_child = right_child = nullptr;
    }
    Node(DataType val) {
        weight = val;
        left_child = right_child = nullptr;
    }
};

template <typename DataType>
int findMaxWeightPath(Node<DataType>* root) {
    if (root == nullptr) {
        return 0;
    }
    if (root->left_child == nullptr && root->right_child == nullptr) {
        return root->weight;
    }
    return root->weight + max(findMaxWeightPath(root->left_child), findMaxWeightPath(root->right_child));
    return 0;
}

template <typename DataType>
int minWeightToBeAdded(Node<DataType>* root, DataType max_weight_path, DataType& max_weight_added) {
    if (root == nullptr) {
        return 0;
    }
    if (root->left_child == nullptr && root->right_child == nullptr) {
        return max_weight_path - root->weight;
    }
    int left_weight_reqd = minWeightToBeAdded(root->left_child, max_weight_path, max_weight_added);
    int right_weight_reqd = minWeightToBeAdded(root->right_child, max_weight_path, max_weight_added);
    int weight_given = min(left_weight_reqd, right_weight_reqd);
    max_weight_added += left_weight_reqd - weight_given;
    max_weight_added += right_weight_reqd - weight_given;
    return weight_given - root->weight;
}

int main() {
    Node<int>* root = new Node<int>(0);
    /*root->left_child = new Node<int>(1);
    root->right_child = new Node<int>(1);
    root->left_child->left_child = new Node<int>(2);
    root->left_child->right_child = new Node<int>(2);
    root->right_child->left_child = new Node<int>(7);
    root->right_child->right_child = new Node<int>(2);*/

    root->left_child = new Node<int>(1);
    root->right_child = new Node<int>(2);
    root->left_child->left_child = new Node<int>(2);
    root->left_child->right_child = new Node<int>(2);
    root->right_child->left_child = new Node<int>(4);
    root->right_child->right_child = new Node<int>(2);
    root->left_child->left_child->left_child = new Node<int>(1);
    root->left_child->left_child->right_child = new Node<int>(3);

    int max_weight_added = 0;

    minWeightToBeAdded(root, findMaxWeightPath(root), max_weight_added);
    cout << max_weight_added;

    return 0;
}