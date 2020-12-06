#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int findFirstUnique(const vector<int> &data) {
    unordered_map<int, int> freqs;
    for (auto val : data) {
        if (freqs.find(val) == freqs.end()) {
            freqs[val] = 1;
        } else {
            ++freqs[val];
        }
    }
    for (auto val : data) {
        if (freqs[val] == 1) {
            return val;
        }
    }
    return -1;
}

int main() {
    vector<int> data;
    data.push_back(2);
    data.push_back(3);
    data.push_back(9);
    data.push_back(3);
    data.push_back(2);
    data.push_back(6);
    cout << findFirstUnique(data);
}