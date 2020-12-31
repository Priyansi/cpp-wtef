#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int maxMoneyStolen(const vector<pair<int, int>> &data, int capacity) {
    int dp[data.size() + 1][capacity + 1];
    fill_n(*dp, (data.size() + 1) * (capacity + 1), 0);
    int money = 0;
    cout << dp[0][2] << endl;
    for (int i = 1; i <= data.size(); ++i) {
        for (int j = 1; j <= capacity; ++j) {
            //cout << dp[i - 1][j] << " " << data[i - 1].second << " " << dp[i - 1][j - data[i - 1].first] << endl;
            if (j >= data[i - 1].first) {
                dp[i][j] = max(dp[i - 1][j], data[i - 1].second + dp[i - 1][j - data[i - 1].first]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
        cout << endl;
    }
    return dp[data.size()][capacity];
}

int main() {
    vector<pair<int, int>> data = {make_pair(1, 1500), make_pair(4, 3000), make_pair(3, 2000), make_pair(1, 2000)};
    cout << maxMoneyStolen(data, 4);
    return 0;
}