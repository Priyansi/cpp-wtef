#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

template <typename DataType>
bool isSubset(vector<DataType> data1, vector<DataType> data2) {
    unordered_set<DataType> hash_table;
    for (DataType val : data1) {
        hash_table.insert(val);
    }
    for (DataType val : data2) {
        if (hash_table.find(val) == hash_table.end()) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<int> data1;
    vector<int> data2;
    data1.push_back(9);
    data1.push_back(4);
    data1.push_back(7);
    data1.push_back(1);
    data1.push_back(-2);
    data1.push_back(6);
    data1.push_back(5);
    data2.push_back(7);
    data2.push_back(1);
    data2.push_back(-2);
    cout << isSubset(data1, data2);
    return 0;
}