/*

*/

#include <limits.h>

#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

vector<int> findThreeSum(vector<int> data, int target) {
    unordered_set<int> elements;
    for (int i = 0; i < data.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            elements.insert(data.at(j));
        }
        for (int j = i + 1; j < data.size(); ++j) {
            if (elements.find(target - data.at(i) - data.at(j)) != elements.end()) {
                return {target - data.at(i) - data.at(j), data.at(i), data.at(j)};
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