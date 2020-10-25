#include <iostream>

using namespace std;

int* mergeArrays(int arr1[], int arr2[], int arr1Size, int arr2Size) {
    int* arr3;  // creating new array
    arr3 = new int[arr1Size + arr2Size];
    int i = 0, j = 0, k = 0;
    while (i < arr1Size && j < arr2Size) {
        if (arr1[i] < arr2[j]) {
            arr3[k++] = arr1[i++];
        } else {
            arr3[k++] = arr2[j++];
        }
    }
    while (i < arr1Size) {
        arr3[k++] = arr1[i++];
    }
    while (j < arr2Size) {
        arr3[k++] = arr2[j++];
    }
    return arr3;  // returning array
}

int main() {
    int size1 = 5, size2 = 3;
    int arr1[size1] = {1, 12, 14, 17, 23};              // creating array 1
    int arr2[size2] = {11, 19, 27};                     // creating array 2
    int* arr3 = mergeArrays(arr1, arr2, size1, size2);  // calling mergeArrays
    for (int i = 0; i < size1 + size2; i++) {
        cout << arr3[i] << " ";
    }
    delete arr3;  // deleting pointer
    return 0;
}