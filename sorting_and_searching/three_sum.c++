/*

*/

#include <limits.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> findThreeSum(vector<int> data, int target) {
    sort(data.begin(), data.end());
    int i, j, left_ptr, right_ptr, sum_reqd, sum;
    for (int i = 0; i < data.size() - 2; ++i) {
        left_ptr = i + 1;
        right_ptr = data.size() - 1;
        while (left_ptr < right_ptr) {
            sum = data.at(left_ptr) + data.at(right_ptr) + data.at(i);
            if (sum == target) {
                return {data.at(i), data.at(left_ptr), data.at(right_ptr)};
            }
            if (sum > target) {
                --right_ptr;
            } else {
                ++left_ptr;
            }
        }
    }
    return {-1};
}

int main(int argc, char* argv[]) {
    int target = stoi(argv[1]);
    vector<int> data = {-1, 2, 1, -4};
    vector<int> pairs = findThreeSum(data, target);
    for (auto val : pairs) {
        cout << val << " ";
    }
    return 0;
}