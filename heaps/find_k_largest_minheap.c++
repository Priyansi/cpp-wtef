// Time Complexity - nlogk + klogk

#include "../header_files/heap.h"

template <typename DataType>
vector<DataType> findKLargest(vector<DataType> data, int k) {
    Heap<DataType> min_heap("min");
    vector<DataType> k_largest;
    for (DataType val : data) {
        min_heap.push(val);
        if (min_heap.getSize() > k) {
            min_heap.pop();
        }
    }
    while (auto i = k_largest.) {
        k_largest.push_back(min_heap.getTop());
        min_heap.pop();
    }
    return k_largest;
}

int main() {
    vector<int> data;
    int k = 3;
    data.push_back(9);
    data.push_back(4);
    data.push_back(7);
    data.push_back(1);
    data.push_back(-2);
    data.push_back(6);
    data.push_back(5);
    for (auto val : findKLargest(data, k)) {
        cout << val << " ";
    }
    return 0;
}