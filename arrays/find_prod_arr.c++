#include <iostream>
#include <numeric>

using namespace std;

int multiply(int arr[], int start, int end) {
    return accumulate(arr + start, arr + end, 1, multiplies<int>());
}

int* findProduct(int arr[], int size) {
    int* product = new int[size];
    int tot_prod = multiply(arr, 0, size);
    int zero_found = 0;
    for (int i = 0; i < size; ++i) {
        if (zero_found) {  // already a zero in the array exists
            product[i] = 0;
        } else {
            if (arr[i] == 0) {
                product[i] = multiply(arr, 0, i) * multiply(arr, i + 1, size);
                zero_found = 1;  // first zero found
            } else {
                product[i] = tot_prod / arr[i];
            }
        }
    }
    return product;
}

int main() {
    int size = 5;
    int arr[size] = {1, 2, 3, 4, 5};

    cout << "Array before product: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int* prodArray = findProduct(arr, size);

    cout << "Array after product: ";
    for (int i = 0; i < size; i++) {
        cout << prodArray[i] << " ";
    }
    cout << endl;
    delete[] prodArray;
    return 0;
}