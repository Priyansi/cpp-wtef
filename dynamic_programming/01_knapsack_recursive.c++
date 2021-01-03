#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int maxMoneyStolen(const vector<pair<int, int>>& data, int capacity, int size) {
    if (size <= 0 || capacity <= 0) {
        return 0;
    }
    if (data[size - 1].first > capacity) {
        return maxMoneyStolen(data, capacity, size - 1);
    }
    if (data[size - 1].first <= capacity) {
        return max(data[size - 1].second + maxMoneyStolen(data, capacity - data[size - 1].first, size - 1), maxMoneyStolen(data, capacity, size - 1));
    }
}

int main() {
    vector<pair<int, int>> data = {make_pair(1, 1500), make_pair(4, 3000), make_pair(3, 2000), make_pair(1, 2000)};
    cout << maxMoneyStolen(data, 4, data.size());
    return 0;
}