#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int insertAtPos(const vector<int>& data, int left_ind, int right_ind, int val) {
    if (left_ind > right_ind) {
        return left_ind;
    }
    if (right_ind >= data.size()) {
        return right_ind;
    }
    int mid_ind = (left_ind + right_ind) / 2;
    if (data[mid_ind] == val) {
        return mid_ind;
    } else if (data[mid_ind] > val) {
        return insertAtPos(data, left_ind, mid_ind - 1, val);
    } else {
        return insertAtPos(data, mid_ind + 1, right_ind, val);
    }
}

int main(int argc, char* argv[]) {
    int val = stoi(argv[1]);
    vector<int> data = {1, 3, 5, 7};
    cout << insertAtPos(data, 0, data.size() - 1, val);
    return 0;
}