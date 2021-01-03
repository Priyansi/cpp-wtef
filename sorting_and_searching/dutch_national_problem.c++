#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> sort012(vector<int> data) {
    int low = 0, mid = 0, high = data.size() - 1;
    while (mid < high) {
        if (data[mid] == 0) {
            swap(data[low], data[mid]);
            ++low;
            ++mid;
        } else if (data[mid] == 1) {
            ++mid;
        } else {
            swap(data[mid], data[high]);
            --high;
            ++mid;
        }
    }
    return data;
}

int main(int argc, char *argv[]) {
    vector<int> data = {2, 0, 0, 1, 2, 1, 0};
    vector<int> result = sort012(data);
    for (auto val : result) {
        cout << val << " ";
    }
    return 0;
}