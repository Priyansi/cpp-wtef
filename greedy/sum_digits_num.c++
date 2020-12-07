#include <iostream>
#include <string>

using namespace std;

int sumOfDigitsEqualsNum(int num_digits, int sum) {
    string num = "";
    while (sum >= 9) {
        num.append("9");
        sum -= 9;
    }
    num.append(to_string(sum));
    while (num.length() < num_digits) {
        num.append("0");
    }
    return stoi(num);
}

int main(int argc, char* argv[]) {
    int num_digits = stoi(argv[1]);
    int sum = stoi(argv[2]);
    cout << sumOfDigitsEqualsNum(num_digits, sum);
    return 0;
}