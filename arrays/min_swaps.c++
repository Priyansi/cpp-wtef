/*
Description - Returns minimum number of swaps so that elements at even indices are divisible by 2 and at odd indices are not
Time Complexity - O(n)
Space Complexity - O(1)
*/

#include <iostream>

using namespace std;

int minSwaps(int arr[], int size) {
    int num_swaps = 0;
    for (int i = 0; i < size; i += 2) {
        if (arr[i] % 2 != 0) {
            ++num_swaps;
        }
    }
    return num_swaps;
}

int main() {
    int size = 4;
    int arr[size] = {9, 2, 3, 6};

    cout << "Array : ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    int min = minSwaps(arr, size);
    cout << "Minimum Swaps : " << min << endl;
    return 0;
}