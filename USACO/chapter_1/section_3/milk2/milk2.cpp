/*
ID: virgil.1
TASK: milk2
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin("milk2.in");
    ofstream fout("milk2.out");
    int n;
    fin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        fin >> a[i].first >> a[i].second;
    }
    vector<pair<int, int>> events(2 * n);
    int index = 0;
    for (int i = 0; i < n; i++) {
        events[index] = {a[i].first, 0};
        events[index + 1] = {a[i].second, 1};
        index += 2;
    }
    sort(events.begin(), events.end());
    n = events.size();
    int counter = 0;
    int earliest_schedule = events[0].first;
    int latest_schedule_ended = events[0].first;
    int longest_milking = 0;
    int longest_non_milking = 0;
    for (int i = 0; i < n; i++) {
        if (events[i].second == 1) {
            if (counter == 1) {
                latest_schedule_ended = events[i].first;
                longest_milking = max(longest_milking, events[i].first - earliest_schedule);
            }
            counter--;
        } else {
            if (counter == 0) {
                earliest_schedule = events[i].first;
                longest_non_milking = max(longest_non_milking, events[i].first - latest_schedule_ended);
            }
            counter++;
        }
    }
    fout << longest_milking << " " << longest_non_milking << "\n";
}
