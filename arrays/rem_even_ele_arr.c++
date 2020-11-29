#include <iomanip>
#include <iostream>

using namespace std;

int removeEven(int *&arr, int size) {
    int i, size_new_arr;
    for (i = 0, size_new_arr = 0; i < size; ++i) {
        if (arr[i] % 2 != 0) {
            arr[size_new_arr++] = arr[i];
        }
    }
    return size_new_arr;
}
int main() {
    int size;
    cin >> size;
    int *arr = new int[size];
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }
    size = removeEven(arr, size);
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    return 0;
}
