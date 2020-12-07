#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

pair<int, int> findMoviePair(vector<int> movie_durs, int duration) {
    unordered_map<int, int> index_table;
    pair<int, int> movie_pair = {-1, -1};
    for (int i = 0; i < movie_durs.size(); ++i) {
        index_table[movie_durs.at(i)] = i;
    }
    sort(movie_durs.begin(), movie_durs.end());
    int low_ind = 0, high_ind = movie_durs.size() - 1;
    int sum = 0, max_sum = 0;
    while (low_ind < high_ind) {
        sum = movie_durs.at(low_ind) + movie_durs.at(high_ind);
        if (max_sum < sum && sum < duration) {
            movie_pair.first = movie_durs.at(low_ind);
            movie_pair.second = movie_durs.at(high_ind);
        }
        if (sum == duration) {
            break;
        } else if (sum < duration) {
            ++low_ind;
        } else {
            --high_ind;
        }
    }
    movie_pair.first = index_table[movie_pair.first];
    movie_pair.second = index_table[movie_pair.second];
    return movie_pair;
}

int main(int argc, char* argv[]) {
    int duration = stoi(argv[1]);
    vector<int> movie_durs;
    movie_durs.push_back(90);
    movie_durs.push_back(85);
    movie_durs.push_back(75);
    movie_durs.push_back(60);
    movie_durs.push_back(120);
    movie_durs.push_back(150);
    movie_durs.push_back(125);
    pair<int, int> movie_pair = findMoviePair(movie_durs, duration - 30);
    cout << movie_pair.first << " " << movie_pair.second << endl;
    return 0;
}