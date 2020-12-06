#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

string findPair(const vector<int> &data) {
    unordered_map<int, string> sums;
    int sum;
    for (int i = 0; i < data.size(); ++i) {
        for (int j = i + 1; j < data.size(); ++j) {
            sum = data.at(i) + data.at(j);
            if (sums.find(sum) != sums.end()) {
                return "{" + sums[sum] + ",{" + to_string(data.at(i)) + "," + to_string(data.at(j)) + "}}";
            }
            sums[sum] = "{" + to_string(data.at(i)) + "," + to_string(data.at(j)) + "}";
        }
    }
}
int main() {
    vector<int> data;
    data.push_back(3);
    data.push_back(4);
    data.push_back(7);
    data.push_back(1);
    data.push_back(12);
    data.push_back(9);
    cout << findPair(data);
    return 0;
}