/*
Not Completed
Description - https://leetcode.com/problems/minimum-window-substring/
*/

#include <limits.h>

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool minWindow(const string &s, const string &t) {
    unordered_map<char, int> s_map, t_map;
    for (auto ch : t) {
        if (t_map.find(ch) == t_map.end()) {
            t_map[ch] = 1;
        } else {
            ++t_map[ch];
        }
    }

    int low_ind = 0, high_ind = 0, min_length = INT_MAX, final_low_ind = -1, final_high_ind = -1;
    while (low_ind < s.size() && (t_map.find(s[low_ind]) == t_map.end())) {
        ++low_ind;
    }
    high_ind = low_ind;
    s_map[s[low_ind]] = 1;
    while (high_ind < s.size() && s_map.size() != t_map.size()) {
        ++high_ind;
        if (t_map.find(s[high_ind]) != t_map.end()) {
            if (s_map.find(s[high_ind]) != s_map.end()) {
                ++s_map[s[high_ind]];
            } else {
                s_map[s[high_ind]] = 1;
            }
        }
    }
    if (min_length > high_ind - low_ind + 1) {
        final_low_ind = low_ind;
        final_high_ind = high_ind;
        min_length = final_high_ind - final_low_ind + 1;
    }
    min_length = min(min_length, high_ind - low_ind + 1);
    if (s_map[s[low_ind]] == 1) {
        s_map.erase(s[low_ind++]);
    } else {
        --s_map[s[low_ind]];
    }
    while (low_ind <= high_ind && (t_map.find(s[low_ind]) == t_map.end())) {
        ++low_ind;
    }
    while (high_ind < s.size() && s_map.size() != t_map.size()) {
        ++high_ind;
        if (t_map.find(s[high_ind]) != t_map.end()) {
            if (s_map.find(s[high_ind]) != s_map.end()) {
                ++s_map[s[high_ind]];
            } else {
                s_map[s[high_ind]] = 1;
            }
        }
    }
    while (s_map != t_map) {
        cout << low_ind << endl;
        if (s_map[s[low_ind]] == 1) {
            s_map.erase(s[low_ind]);
        } else {
            --s_map[s[low_ind]];
        }
        ++low_ind;
    }
    // while (s_map != t_map) {
    //     cout << low_ind << s[low_ind] << endl;
    //     if (t_map.find(s[low_ind]) != t_map.end()) {
    //         s_map.erase(s[low_ind]);
    //     }
    //     ++low_ind;
    // }
    cout << low_ind << " " << high_ind << " " << final_low_ind << " " << final_high_ind << endl;
    return true;
}

int main(int argc, char *argv[]) {
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << minWindow(s, t);
    return 0;
}