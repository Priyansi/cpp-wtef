#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int findRowIndex(const vector<vector<int>>& data, int left_ind, int right_ind, int val) {
    if (left_ind >= right_ind) {
        return left_ind;
    }
    int mid_ind = (left_ind + right_ind) / 2;
    if (mid_ind < right_ind && data[mid_ind][0] <= val && data[mid_ind + 1][0] > val) {
        return mid_ind;
    } else if (data[mid_ind][0] > val) {
        return findRowIndex(data, left_ind, mid_ind - 1, val);
    } else {
        return findRowIndex(data, mid_ind + 1, right_ind, val);
    }
}

bool searchSortedMatrix(const vector<vector<int>>& data, int val) {
    int row = findRowIndex(data, 0, data.size() - 1, val);
    int left_ind = 0, right_ind = data[row].size() - 1;
    while (left_ind <= right_ind) {
        int mid_ind = (left_ind + right_ind) / 2;
        if (data[row][mid_ind] == val) {
            return true;
        } else if (data[row][mid_ind] > val) {
            right_ind = mid_ind - 1;
        } else {
            left_ind = mid_ind + 1;
        }
    }
    return false;
}

int main(int argc, char* argv[]) {
    int val = stoi(argv[1]);
    vector<vector<int>> data = {{10, 11, 12, 13}, {14, 15, 16, 17}, {27, 29, 30, 31}, {32, 33, 39, 80}};
    cout << searchSortedMatrix(data, val);
    return 0;
}