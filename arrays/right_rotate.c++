#include <iostream>

using namespace std;

void rotateArray(int arr[], int size) {
    int last_element = arr[size - 1];
    for (int i = size - 1; i > 0; --i) {
        arr[i] = arr[i - 1];
    }
    arr[0] = last_element;
}

int main() {
    int size = 6;
    int arr[size] = {3, 6, 1, 8, 4, 2};
    cout << "Array before rotation: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    rotateArray(arr, size);

    cout << "Array after rotation: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}