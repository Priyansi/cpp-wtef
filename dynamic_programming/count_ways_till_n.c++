#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int waysToReachNum(int num) {
    int waysToReachN[num + 1];
    fill(waysToReachN, waysToReachN + num + 1, 0);
    waysToReachN[1] = 1;
    for (int i = 1; i <= num; ++i) {
        if (i + 1 <= num) {
            ++waysToReachN[i + 1];
        }
        if (2 * i <= num) {
            ++waysToReachN[2 * i];
        }
        if (3 * i <= num) {
            ++waysToReachN[3 * i];
        }
        cout << waysToReachN[i] << endl;
    }
    return waysToReachN[num];
}

int main() {
    cout << waysToReachNum(7);
    return 0;
}