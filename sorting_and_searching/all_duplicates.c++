#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> findDuplicates(vector<int> data) {
    vector<int> duplicates;
    sort(data.begin(), data.end());
    for (int i = 0; i < data.size() - 1;) {
        if (data.at(i) == data.at(i + 1)) {
            duplicates.push_back(data.at(i));
            while ((i < data.size() - 1) && (data.at(i) == data.at(i + 1))) {
                ++i;
            }
        } else {
            ++i;
        }
    }
    return duplicates;
}

int main() {
    vector<int> data = {1, 3, 4, 3, 5, 4, 100, 100};
    vector<int> duplicates = findDuplicates(data);
    for (auto val : duplicates) {
        cout << val << " ";
    }
    return 0;
}