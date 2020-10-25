#include <algorithm>
#include <iostream>

using namespace std;

// try with hash table

//Return 2 elements of arr that sum to the given value
int* findSum(int arr[], int value, int size) {
    // Sorting function is prepended as sort(arr, low, high)
    sort(arr, arr + size);
    int start_ind = 0, end_ind = size - 1, sum;
    while (start_ind < end_ind) {
        sum = arr[start_ind] + arr[end_ind];
        if (sum == value) {
            arr[0] = arr[start_ind];
            arr[1] = arr[end_ind];
            break;
        }
        if (sum > value) {
            --end_ind;
        } else {
            ++start_ind;
        }
    }
    // Write your code here
    return arr;
}

int main() {
    int size = 5, value = 9;
    int arr[size] = {2, 4, 5, 7, 8};

    if (size > 0) {
        int* arr2 = findSum(arr, value, size);
        int num1 = arr2[0];
        int num2 = arr2[1];

        if ((num1 + num2) != value)
            cout << "Not Found" << endl;
        else {
            cout << "Number 1 = " << num1 << endl;
            cout << "Number 2 = " << num2 << endl;
            cout << "Sum = " << num1 + num2 << endl;
        }
    } else {
        cout << "Input Array is Empty!" << endl;
    }
}