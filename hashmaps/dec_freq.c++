#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

bool compareFreqs(vector<int> freq1, vector<int> freq2) {
    if (freq1[0] != freq2[0]) {
        return freq1[0] > freq2[0];
    }
    return freq1[1] < freq2[1];
}
vector<int> sortDecreasingFreq(vector<int> arr) {
    unordered_map<int, pair<int, int>> freqs;
    for (int i = 0; i < arr.size(); ++i) {
        if (freqs.find(arr[i]) == freqs.end()) {
            freqs.insert(make_pair((arr[i]), make_pair(1, i)));
        } else {
            ++(freqs[arr[i]]).first;
        }
    }
    vector<vector<int>> sorted_freqs;
    for (auto it : freqs) {
        sorted_freqs.push_back({it.second.first, it.second.second, it.first});
    }
    sort(sorted_freqs.begin(), sorted_freqs.end(), compareFreqs);
    vector<int> sorted_arr;
    for (vector<int> freq : sorted_freqs) {
        while (freq[0]--) {
            sorted_arr.push_back(freq[2]);
        }
    }
    return sorted_arr;
}

int main() {
    vector<int> data;
    data.push_back(2);
    data.push_back(5);
    data.push_back(2);
    data.push_back(6);
    data.push_back(-1);
    data.push_back(9999999);
    data.push_back(5);
    data.push_back(8);
    data.push_back(8);
    data.push_back(8);
    vector<int> sorted_arr = sortDecreasingFreq(data);
    for (auto val : sorted_arr) {
        cout << val << " ";
    }
    return 0;
}