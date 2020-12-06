#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool findSubZero(const vector<int> &data) {
    int total_max = *max_element(data.begin(), data.end());
    int total_min = *min_element(data.begin(), data.end());
    int sum_so_far = data.at(0);
    for (int i = 1; i < data.size(); ++i) {
        if (sum_so_far + data.at(i) == 0) {
            return true;
        }
        if (-(sum_so_far + data.at(i)) < total_min || -(sum_so_far + data.at(i) > total_max)) {
            sum_so_far = data.at(i);
        } else {
            sum_so_far += data.at(i);
        }
    }
    return false;
}

int main() {
    vector<int> data;
    data.push_back(6);
    data.push_back(4);
    data.push_back(-7);
    data.push_back(3);
    data.push_back(12);
    data.push_back(9);
    cout << findSubZero(data);
    return 0;
}
