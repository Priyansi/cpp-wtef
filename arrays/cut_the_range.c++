#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

vector<vector<int>> cutRange(const vector<int> &range, const vector<int> &cut_pos) {
    vector<vector<int>> cut_ranges;
    int start = range[0];
    int end;
    for (int i = 0; i < cut_pos.size(); ++i) {
        end = cut_pos[i];
        if (end - start > 0) {
            cut_ranges.push_back({start, end - 1});
        }
        start = end + 1;
    }
    cut_ranges.push_back({start, range[1]});
    return cut_ranges;
}

int main() {
    vector<int> range;
    vector<int> cut_pos;
    range.push_back(1);
    range.push_back(100);
    cut_pos.push_back(3);
    cut_pos.push_back(4);
    cut_pos.push_back(7);
    vector<vector<int>> cut_ranges = cutRange(range, cut_pos);
    for (vector<int> cut_range : cut_ranges) {
        cout << cut_range[0] << " " << cut_range[1] << endl;
    }
    return 0;
}