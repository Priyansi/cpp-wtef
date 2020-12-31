#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int calcFirstOccurrence(const vector<int>& data, int left_ind, int right_ind, int val) {
    if (left_ind > right_ind) {
        return -1;
    }
    int mid_ind = (left_ind + right_ind) / 2;
    if (data[mid_ind] == val) {
        if (mid_ind - 1 >= 0 && data[mid_ind - 1] == val) {
            return calcFirstOccurrence(data, left_ind, mid_ind - 1, val);
        } else {
            return mid_ind;
        }
    } else if (data[mid_ind] > val) {
        return calcFirstOccurrence(data, left_ind, mid_ind - 1, val);
    } else {
        return calcFirstOccurrence(data, mid_ind + 1, right_ind, val);
    }
}

int calcLastOccurrence(const vector<int>& data, int left_ind, int right_ind, int val) {
    if (left_ind > right_ind) {
        return -1;
    }
    int mid_ind = (left_ind + right_ind) / 2;
    if (data[mid_ind] == val) {
        if (mid_ind + 1 < data.size() && data[mid_ind + 1] == val) {
            return calcLastOccurrence(data, mid_ind + 1, right_ind, val);
        } else {
            return mid_ind;
        }
    } else if (data[mid_ind] > val) {
        return calcLastOccurrence(data, left_ind, mid_ind - 1, val);
    } else {
        return calcLastOccurrence(data, mid_ind + 1, right_ind, val);
    }
}

int calcFreqOfOccurance(const vector<int>& data, int val) {
    int first_occur = calcFirstOccurrence(data, 0, data.size() - 1, val);
    int last_occur = calcLastOccurrence(data, 0, data.size() - 1, val);
    return ((first_occur != -1) ? last_occur - first_occur + 1 : 0);
}

int main(int argc, char* argv[]) {
    int val = stoi(argv[1]);
    vector<int> data = {-5, -3, 0, 1, 3, 3, 3, 4, 5};
    cout << calcFreqOfOccurance(data, val);
    return 0;
}