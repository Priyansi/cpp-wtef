#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int maxMoneyStolenRecr(const vector<pair<int, int>>& data, int capacity, int size, vector<vector<int>>& cache) {
    if (size <= 0 || capacity <= 0) {
        return 0;
    }
    if (cache[capacity][size] > 0) {
        if (data[size - 1].first > capacity) {
            cache[capacity][size] = maxMoneyStolenRecr(data, capacity, size - 1, cache);
        } else {
            cache[capacity][size] = max(data[size - 1].second + maxMoneyStolenRecr(data, capacity - data[size - 1].first, size - 1, cache), maxMoneyStolenRecr(data, capacity, size - 1, cache));
        }
    }
    return cache[capacity][size];
}

int maxMoneyStolen(const vector<pair<int, int>>& data, int capacity, int size) {
    vector<vector<int>> cache(capacity + 1, vector<int>(size + 1, -1));
    return maxMoneyStolenRecr(data, capacity, size - 1, cache);
}

int main() {
    vector<pair<int, int>> data = {make_pair(1, 1500), make_pair(4, 3000), make_pair(3, 2000), make_pair(1, 2000)};
    cout << maxMoneyStolen(data, 4, data.size());
    return 0;
}