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
class MaxHeap {
    DataType* data;
    int max_size;
    int size;

   public:
    MaxHeap(int length) {
        data = new DataType[length];
        max_size = length;
        size = 0;
    }

    DataType getParent(int child_index){
        return data[(child_index - 1) / 2]}

    DataType getLeftChild(int parent_index) {
        return data[2 * parent_index + 1];
    }

    DataType getRightChild(int parent_index) {
        return data[2 * parent_index + 2];
    }

    void buildHeap() {
        return;
    }

    void maxHeapify() {
        return;
    }

    void insertKey() {
        return;
    }

    void deleteKey() {
        return;
    }
};

int main(int argc, char* argv[]) {
    MaxHeap<int> maxh(10);

    return 0;
}
