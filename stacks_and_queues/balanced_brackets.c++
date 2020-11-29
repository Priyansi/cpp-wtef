#include <unordered_set>
#include "../header_files/stack_ll.h"

char matchingBracket(char closing_bracket) {
    switch (closing_bracket) {
        case ')':
            return '(';
        case '}':
            return '{';
        case ']':
            return '[';
    }
}

bool isClosingBracket(char ch) {
    unordered_set<char> closing_brackets = {')', '}', ']'};
    if (closing_brackets.find(ch) != closing_brackets.end()) {
        return true;
    }
    return false;
}

bool isBalanced(string brackets) {
    Stack<char> s;
    for (auto b : brackets) {
        if (isClosingBracket(b)) {
            if (s.peek()->data != matchingBracket(b)) {
                return false;
            }
            s.pop();
        } else {
            s.push(b);
        }
    }
    if (!s.isEmpty()) {
        return false;
    }
    return true;
}

int main(int argc, char* argv[]) {
    string brackets = argv[1];
    cout << isBalanced(brackets);
}