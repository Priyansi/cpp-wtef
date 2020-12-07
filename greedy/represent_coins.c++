/*
Problem Statement: #
Given an infinite number of quarters (25 cents), dimes (10 cents), nickels (5 cents) and pennies (1 cent),
implement a function to calculate the number of COINS to represent Vcents. (Minimum numbers of
total coins)
Input #
A variable V (total Money to convert to coins
Output #
The number of coins and a statement that tells the number and type of coins
Sample Input #
V = 19
Sample Output #
10, 5, 1, 1, 1, 1
*/

#include <iostream>
#include <string>

using namespace std;

string addCoinsForCent(int& val_to_repr, int cent) {
    string coins_repr = "";
    while (val_to_repr >= cent) {
        coins_repr.append(to_string(cent) + ",");
        val_to_repr -= cent;
    }
    return coins_repr;
}

string coinsReqToRepr(int val_to_repr) {
    string coins_repr = "";
    coins_repr.append(addCoinsForCent(val_to_repr, 25));
    coins_repr.append(addCoinsForCent(val_to_repr, 10));
    coins_repr.append(addCoinsForCent(val_to_repr, 5));
    coins_repr.append(addCoinsForCent(val_to_repr, 1));
    return coins_repr.substr(0, coins_repr.size() - 1);
}

int main(int argc, char* argv[]) {
    int val_to_repr = stoi(argv[1]);
    cout << coinsReqToRepr(val_to_repr);
    return 0;
}