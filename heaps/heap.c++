#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename DataType>
class Heap {
    vector<DataType> data;
    bool is_max_heap;

    int getParentIndex(int child_index) {
        return (child_index - 1) / 2;
    }

    int getLeftChildIndex(int parent_index) {
        return 2 * parent_index + 1;
    }

    int getRightChildIndex(int parent_index) {
        return 2 * parent_index + 2;
    }

    void maxHeapify(int parent_index) {
        int max_ele_ind = parent_index;
        int left_child_ind = getLeftChildIndex(parent_index);
        int right_child_ind = getRightChildIndex(parent_index);

        if (left_child_ind < this->getSize() && data.at(left_child_ind) > data.at(max_ele_ind)) {
            max_ele_ind = left_child_ind;
        }
        if (right_child_ind < this->getSize() && data.at(right_child_ind) > data.at(max_ele_ind)) {
            max_ele_ind = right_child_ind;
        }
        if (max_ele_ind != parent_index) {
            swap(data.at(max_ele_ind), data.at(parent_index));
            maxHeapify(max_ele_ind);
        }
    }

    void minHeapify(int parent_index) {
        int min_ele_ind = parent_index;
        int left_child_ind = getLeftChildIndex(parent_index);
        int right_child_ind = getRightChildIndex(parent_index);

        if (left_child_ind < this->getSize() && data.at(left_child_ind) < data.at(min_ele_ind)) {
            min_ele_ind = left_child_ind;
        }
        if (right_child_ind < this->getSize() && data.at(right_child_ind) < data.at(min_ele_ind)) {
            min_ele_ind = right_child_ind;
        }
        if (min_ele_ind != parent_index) {
            swap(data.at(min_ele_ind), data.at(parent_index));
            minHeapify(min_ele_ind);
        }
    }

   public:
    Heap(string type) {
        this->is_max_heap = (type.compare("max") == 0) ? true : false;
    }

    void push(DataType key) {
        data.push_back(key);
        if (is_max_heap) {
            maxHeapify(this->getParentIndex(this->getSize() - 1));
        } else {
            minHeapify(this->getParentIndex(this->getSize() - 1));
        }
    }

    void pop() {
        if (this->getSize() > 0) {
            swap(this->data.at(0), this->data.at(this->getSize() - 1));
            this->data.pop_back();
            if (is_max_heap) {
                maxHeapify(0);
            } else {
                minHeapify(0);
            }
        }
    }

    void changeHeapType() {
        is_max_heap = !is_max_heap;
        if (is_max_heap) {
            for (int ind = this->getParentIndex(this->getSize() - 1); ind >= 0; --ind) {
                maxHeapify(ind);
            }
        } else {
            for (int ind = this->getParentIndex(this->getSize() - 1); ind >= 0; --ind) {
                minHeapify(ind);
            }
        }
    }

    int getSize() {
        return this->data.size();
    }

    DataType getTop() {
        return this->data.front();
    }

    void display() {
        for (DataType val : this->data) {
            cout << val << " ";
        }
        cout << "\n";
    }
};

int main(int argc, char* argv[]) {
    Heap<int> maxh("max");
    maxh.push(9);
    maxh.push(4);
    maxh.push(7);
    maxh.push(1);
    maxh.push(-2);
    maxh.push(6);
    maxh.push(5);
    maxh.display();
    maxh.pop();
    maxh.pop();
    maxh.changeHeapType();
    maxh.display();
    return 0;
}
