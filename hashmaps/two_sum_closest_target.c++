/*
Description - 
You are on a flight and wanna watch two movies during this flight.
You are given List<Integer> movieDurations which includes all the movie durations.
You are also given the duration of the flight which is d in minutes.
Now, you need to pick two movies and the total duration of the two movies is less than or equal to (d - 30min).

Find the pair of movies with the longest total duration and return they indexes. If multiple found, return the pair with the longest movie.

Example 1:

Input: movieDurations = [90, 85, 75, 60, 120, 150, 125], d = 250
Output: [0, 6]
Explanation: movieDurations[0] + movieDurations[6] = 90 + 125 = 215 is the maximum number within 220 (250min - 30min)
Time Complexity - O(nlogn)
*/

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