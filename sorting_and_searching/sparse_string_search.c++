#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int searchSparseArray(const vector<string>& data, int left_ind, int right_ind, string val) {
    if (left_ind > right_ind) {
        return -1;
    }
    int mid_ind = (left_ind + right_ind) / 2;
    if (data[mid_ind] == "") {
        int left = mid_ind - 1;
        int right = mid_ind + 1;
        while (1) {
            if (left < left_ind && right > right_ind) {
                return -1;
            } else if (left >= left_ind && data[left] != "") {
                mid_ind = left;
                break;
            } else if (right <= right_ind && data[right] != "") {
                mid_ind = right;
                break;
            } else {
                ++right;
                --left;
            }
        }
    }
    if (data[mid_ind].compare(val) == 0) {
        return mid_ind;
    } else if (data[mid_ind].compare(val) > 0) {
        return searchSparseArray(data, left_ind, mid_ind - 1, val);
    } else {
        return searchSparseArray(data, mid_ind + 1, right_ind, val);
    }
}

int main(int argc, char* argv[]) {
    string val = argv[1];
    vector<string> data = {"", "educative", "", "", "", "hello", "", "learning", "world", "", "", ""};
    cout << searchSparseArray(data, 0, data.size() - 1, val);
    return 0;
}

