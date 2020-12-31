/*
You are given n pairs of numbers. In every pair, the first number is always smaller than the second number.

Now, we define a pair (c, d) can follow another pair (a, b) if and only if b < c. Chain of pairs can be formed in this fashion.

Given a set of pairs, find the length longest chain which can be formed. You needn't use up all the given pairs. You can select pairs in any order.

Example 1:
Input: [[1,2], [2,3], [3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4]
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool compare(const pair<int, int> &pair1, const pair<int, int> &pair2) {
    return pair1.second < pair2.second;
}

int findLongestChain(vector<pair<int, int>> &pairs) {
    sort(pairs.begin(), pairs.end(), compare);
    pair<int, int> last_pair = pairs[0];
    int longest_chain = 1;
    for (int i = 1; i < pairs.size(); ++i) {
        if (last_pair.second < pairs[i].first) {
            ++longest_chain;
            last_pair = pairs[i];
        }
    }
    return longest_chain;
}

int main() {
    vector<pair<int, int>> pairs = {{1, 2}, {2, 3}, {3, 4}};
    cout << findLongestChain(pairs);
}