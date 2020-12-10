/*
Description -
Write an efficient function that checks whether any permutation ↴ of an input string is a palindrome. ↴

You can assume the input string only contains lowercase letters.

Examples:

"civic" should return True
"ivicc" should return True
"civil" should return False
"livci" should return False
Time Complexity - O(n)
*/

#include <iostream>
#include <unordered_set>

using namespace std;

bool canBePalindrome(string str) {
    unordered_set<int> elements;
    for (char ch : str) {
        if (elements.find(ch) != elements.end()) {
            elements.erase(ch);
        } else {
            elements.insert(ch);
        }
    }

    return ((elements.size() <= 1) ? true : false);
}

int main(int argc, char* argv[]) {
    string str = argv[1];
    cout << canBePalindrome(str);
    return 0;
}