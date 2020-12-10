#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int longestIncSubSeq(const vector<int> &data) {
    int dp[data.size()] = {1};
    for (int i = 0; i < data.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (data.at(i) > data.at(j) && dp[i] > dp[j]) {
                ++dp[i];
            }
        }
    }
    return *max_element(dp, dp + data.size());
}

int main() {
    vector<int> data = {0, 3, 1, 6, 2, 2, 7};
    cout << longestIncSubSeq(data);
}