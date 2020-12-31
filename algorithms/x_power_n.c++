#include <iostream>
using namespace std;

float power_recr(int x, int n) {
    if (n == 0) {
        return 1;
    } else if (n == -1) {
        return 1 / x;
    } else if (n % 2 == 0) {
        return power_recr(x, n / 2) * power_recr(x, n / 2);
    } else {
        return x * power_recr(x, (n - 1) / 2) * power_recr(x, (n - 1) / 2);
    }
}

float power_iter(int x, int n) {
    if (x == 1) {
        return x;
    }
    double result = 1;
    if (n < 0) {
        x = 1 / x;
        n = -n;
    }
    while (n > 0) {
        if (n % 2 == 1) {
            result *= x;
        }
        x *= x;
        n >>= 1;
    }
    return result;
}

int main() {
    cout << power_recr(2, -2) << endl;
    cout << power_iter(2, 10) << endl;
    return 0;
}
