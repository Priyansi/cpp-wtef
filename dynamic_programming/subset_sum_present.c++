#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool subsetSumPresent(const vector<int> &data, int sum) {
    bool cache[data.size() + 1][sum + 1];
    for (int i = 0; i <= data.size(); ++i) {
        for (int j = 0; j <= sum; ++j) {
            if (j == 0) {
                // empty subset when sum = 0 and elements >= 0
                cache[i][j] = true;
            } else if (i == 0) {
                // sum can't be zero when elements > 0
                cache[i][j] = false;
            } else if (j >= data[i - 1]) {
                cache[i][j] = cache[i - 1][j] || cache[i][j - data[i - 1]];
            } else {
                cache[i][j] = cache[i - 1][j];
            }
        }
    }
    return cache[data.size()][sum];
}

int main() {
    vector<int> data = {2, 3, 7, 8, 10};
    cout << subsetSumPresent(data, 13);
    return 0;
}