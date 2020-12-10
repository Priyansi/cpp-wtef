/*

*/

#include <limits.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int findThreeSumClosestTarget(vector<int> data, int target) {
    int closest_sum = INT_MIN;
    sort(data.begin(), data.end());
    int i, j, left_ptr, right_ptr, sum_reqd, sum;
    for (int i = 0; i < data.size() - 2; ++i) {
        left_ptr = i + 1;
        right_ptr = data.size() - 1;
        sum_reqd = target - data.at(i);
        while (left_ptr < right_ptr) {
            sum = data.at(left_ptr) + data.at(right_ptr) + data.at(i);
            if (abs(sum_reqd - closest_sum) > abs(sum_reqd - sum)) {
                closest_sum = sum;
            }
            if (sum > sum_reqd) {
                --right_ptr;
            } else {
                ++left_ptr;
            }
        }
    }
    return closest_sum;
}

int main(int argc, char* argv[]) {
    int target = stoi(argv[1]);
    vector<int> data = {-1, 2, 1, -4};
    cout << findThreeSumClosestTarget(data, target);

    return 0;
}