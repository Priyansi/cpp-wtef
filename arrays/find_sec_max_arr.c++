#include <climits>
#include <iostream>

using namespace std;

int findSecondMaximum(int arr[], int size) {
    int secondmax = INT_MIN;
    int firstmax = INT_MIN;
    for (int i = 0; i < size; ++i) {
        if (arr[i] > firstmax) {
            secondmax = firstmax;
            firstmax = arr[i];
        } else if (arr[i] > secondmax) {
            secondmax = arr[i];
        }
    }
    return secondmax;
}

int main() {
    int size = 5;
    int arr[size] = {-2, -33, -10, -33, -456};

    cout << "Array: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    int secMax = findSecondMaximum(arr, size);
    cout << "Second maximum: " << secMax << endl;
    return 0;
}