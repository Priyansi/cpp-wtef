#include <iostream>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

pair<int, int> findSum(const vector<int>& data, int sum) {
    unordered_set<int> elements;
    pair<int, int> result = {-1, -1};
    for (auto val : data) {
        if (elements.find(sum - val) != elements.end()) {
            result.first = val;
            result.second = sum - val;
            break;
        } else {
            elements.insert(val);
        }
    }
    return result;
}

int main(int argc, char* argv[]) {
    int sum = stoi(argv[1]);
    vector<int> data;
    data.push_back(21);
    data.push_back(3);
    data.push_back(60);
    data.push_back(4);
    data.push_back(12);
    data.push_back(9);
    pair<int, int> result = findSum(data, sum);
    cout << result.first << " " << result.second << endl;
    return 0;
}