#include <algorithm>
#include <iostream>
#include <utility>

using namespace std;

void maxMin(int arr[], int size) {
    sort(arr, arr + size);
    int max_ele = arr[size - 1] + 1;
    int max_ind = size - 1;
    int min_ind = 0;
    for (int i = 0; i < size; ++i) {
        if (i % 2) {
            arr[i] += (arr[min_ind] % max_ele) * max_ele;
            ++min_ind;
        } else {
            arr[i] += (arr[max_ind] % max_ele) * max_ele;
            --max_ind;
        }
    }
    for (int i = 0; i < size; ++i) {
        arr[i] /= max_ele;
    }
}

int main() {
    int size = 6;
    int arr[size] = {1, 2, 3, 4, 5, 6};
    cout << "Array before min/max: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    maxMin(arr, size);

    cout << "Array after min/max: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}