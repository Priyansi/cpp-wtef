#include <algorithm>
#include <iostream>
#include <numeric>
#include <utility>

using namespace std;

int maxSumFromEndsTillK(int arr[], int size, int k) {
    int left_ind = 0, right_ind = size - 1, sum = 0;
    if (k >= size) {
        return accumulate(arr, arr + size, 0);
    }
    while (k--) {
        if (arr[left_ind] > arr[right_ind]) {
            sum += arr[left_ind++];
        } else {
            sum += arr[right_ind++];
        }
    }
    return sum;
}

int main() {
    int size = 5;
    int arr[size] = {5, 1, 2, 9, 1};
    cout << maxSumFromEndsTillK(arr, size, 3);
}