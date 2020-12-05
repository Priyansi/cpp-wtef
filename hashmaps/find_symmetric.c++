#include <iostream>
#include <unordered_set>

using namespace std;

string findSymmetric(int arr[][2], int size) {
    unordered_set<string> hash_table;
    string sym_pairs = "";
    for (int i = 0; i < size; i++) {
        string first = to_string(arr[i][0]);
        string second = to_string(arr[i][1]);
        if (hash_table.find(second + "," + first) != hash_table.end()) {
            sym_pairs.append("{" + first + ", " + second + "}{" + second + ", " + first + "}");
        } else {
            hash_table.insert(first + "," + second);
        }
    }
    return sym_pairs;
}

int main() {
    int size;
    cin >> size;
    int arr[size][2];
    for (int i = 0; i < size; ++i) {
        cin >> arr[i][0];
        cin >> arr[i][1];
    }
    cout << findSymmetric(arr, size);
}