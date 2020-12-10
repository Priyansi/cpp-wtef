#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename DataType>
class Heap {
    vector<DataType> data;
    bool is_max_heap;
    vector<int> i;
    vector<int> j;

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
            swap(i.at(max_ele_ind), i.at(parent_index));
            swap(j.at(max_ele_ind), j.at(parent_index));
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
            swap(i.at(min_ele_ind), i.at(parent_index));
            swap(j.at(min_ele_ind), j.at(parent_index));
            minHeapify(min_ele_ind);
        }
    }

   public:
    Heap(string type) {
        this->is_max_heap = (type.compare("max") == 0) ? true : false;
    }

    void push(DataType key, int i_ind, int j_ind) {
        data.push_back(key);
        i.push_back(i_ind);
        j.push_back(j_ind);
        if (is_max_heap) {
            maxHeapify(this->getParentIndex(this->getSize() - 1));
        } else {
            minHeapify(this->getParentIndex(this->getSize() - 1));
        }
    }

    void pop() {
        if (this->getSize() > 0) {
            swap(this->data.at(0), this->data.at(this->getSize() - 1));
            swap(this->i.at(0), this->i.at(this->getSize() - 1));
            swap(this->j.at(0), this->j.at(this->getSize() - 1));
            this->data.pop_back();
            this->i.pop_back();
            this->j.pop_back();
            if (is_max_heap) {
                maxHeapify(0);
            } else {
                minHeapify(0);
            }
        }
    }

    int getSize() {
        return this->data.size();
    }

    DataType getTop() {
        return this->data.front();
    }

    int getTopI() {
        return this->i.front();
    }
    int getTopJ() {
        return this->j.front();
    }

    void display() {
        for (int ind = 0; ind < this->getSize(); ++ind) {
            cout << this->data.at(ind) << " " << this->i.at(ind) << " " << this->j.at(ind) << endl;
        }
        cout << "\n";
    }
};

int to_num(char ch) {
    return ch - '0';
}

int max_dollars_left(string arr[], int rows, int cols, int k) {
    int is_bomb[rows][cols] = {{0}};
    int i, j, l;
    bool no_bomb = true;
    for (i = 0; i < rows; ++i) {
        for (j = 0; j < cols; ++j) {
            if (arr[i][j] == 'B') {
                for (l = 0; l < cols; ++l) {
                    is_bomb[i][l] = 1;
                }
                no_bomb = false;
            }
        }
    }
    for (i = 0; i < rows; ++i) {
        for (j = 0; j < cols; ++j) {
            if (arr[i][j] == 'B') {
                for (l = 0; l < rows; ++l) {
                    is_bomb[l][j] = 1;
                }
            }
            no_bomb = false;
        }
    }
    if (no_bomb) {
        int sum = 0;
        for (i = 0; i < rows; ++i) {
            for (j = 0; j < cols; ++j) {
                sum += arr[i][j];
            }
        }
        return sum;
    } else {
        bool only_bomb = true;
        for (i = 0; i < rows; ++i) {
            for (j = 0; j < cols; ++j) {
                if (is_bomb[i][j] == 0) {
                    only_bomb = false;
                }
            }
        }
        if (only_bomb) {
            return 0;
        }
    }
    Heap<int> not_affected("min");
    Heap<int> is_affected("max");
    for (i = 0; i < rows; ++i) {
        for (j = 0; j < cols; ++j) {
            if (arr[i][j] != 'B') {
                if (is_bomb[i][j] == 1) {
                    is_affected.push(to_num(arr[i][j]), i, j);
                } else {
                    not_affected.push(to_num(arr[i][j]), i, j);
                }
            }
        }
    }
    while (k--) {
        if (is_affected.getTop() < not_affected.getTop()) {
            break;
        }
        swap(arr[is_affected.getTopI()][is_affected.getTopJ()], arr[not_affected.getTopI()][not_affected.getTopJ()]);
    }
    int sum = 0;
    for (i = 0; i < rows; ++i) {
        for (j = 0; j < cols; ++j) {
            if (is_bomb[i][j] == 0) {
                sum += to_num(arr[i][j]);
            }
        }
    }
    return sum;
}

int main(int argc, char* argv[]) {
    int rows = 3;
    int cols = 5;
    int k = 1;
    string arr[rows] = {"B8B3B",
                        "53243",
                        "32452"};
    cout << max_dollars_left(arr, rows, cols, k) << endl;
    return 0;
}