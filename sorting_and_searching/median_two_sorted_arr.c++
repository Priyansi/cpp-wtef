#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int searchRotatedArray(const vector<int>& data, int left_ind, int right_ind, int val) {
    if (left_ind > right_ind) {
        return -1;
    }
    int mid_ind = (left_ind + right_ind) / 2;
    if (data.at(mid_ind) == val) {
        return mid_ind;
    }
    // if left side is sorted
    if (data.at(left_ind) <= data.at(mid_ind)) {
        // if element i present in left side
        if (data.at(mid_ind) > val && data.at(left_ind) <= val) {
            return searchRotatedArray(data, left_ind, mid_ind - 1, val);
        } else {
            // if element is not present in left side
            return searchRotatedArray(data, mid_ind + 1, right_ind, val);
        }
    } else {  // if right side is sorted
        // if element is present in right side
        if (data.at(mid_ind) < val && data.at(right_ind) >= val) {
            return searchRotatedArray(data, mid_ind + 1, right_ind, val);
        } else {
            // if element is not present in right side
            return searchRotatedArray(data, left_ind, mid_ind - 1, val);
        }
    }
}

int main(int argc, char* argv[]) {
    int val = stoi(argv[1]);
    vector<int> data = {7, 8, 9, 0, 3, 5, 6};
    cout << searchRotatedArray(data, 0, data.size() - 1, val);
    return 0;
}