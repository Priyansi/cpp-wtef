#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

string tracePath(const unordered_map<string, string> &hash_map) {
    string path = "";
    string city_start = "";
    unordered_set<string> cities;
    for (auto &it : hash_map) {
        cities.insert(it.second);
    }
    for (auto &it : hash_map) {
        if (cities.find(it.first) == cities.end()) {
            city_start = it.first;
        }
    }
    while (hash_map.find(city_start) != hash_map.end()) {
        path.append(city_start + "->" + hash_map.at(city_start) + ", ");
        city_start = hash_map.at(city_start);
    }
    return path.substr(0, path.length() - 2);
}

int main() {
    unordered_map<string, string> hash_map = {{"NewYork", "Chicago"}, {"Boston", "Texas"}, {"Missouri", "NewYork"}, {"Texas", "Missouri"}};
    cout << tracePath(hash_map);
}