#include <iostream>
#include <unordered_map>

using namespace std;

int findFirstUnique(int arr[], int size) {
    unordered_map<int, int> freqs;
    for (int i = 0; i < size; ++i) {
        ++freqs[arr[i]];
    }
    for (int i = 0; i < size; ++i) {
        if (freqs[arr[i]] == 1) {
            return arr[i];
        }
    }
    return -1;
}

int main() {
    int size = 6;
    int arr[size] = {2, 54, 7, 2, 6, 54};

    cout << "Array: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    int unique = findFirstUnique(arr, size);
    cout << "First Unique in an Array: " << unique << endl;
    return 0;
}