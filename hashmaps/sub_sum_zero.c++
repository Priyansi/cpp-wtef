#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

bool findSubZero(const vector<int> &data) {
    unordered_set<int> sums;
    int sum_so_far = 0;
    for (int i = 0; i < data.size(); ++i) {
        sum_so_far += data.at(i);
        if (sums.find(sum_so_far) != sums.end()) {
            return true;
        }
        sums.insert(sum_so_far);
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
