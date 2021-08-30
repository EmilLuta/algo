#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e9 + 7;

char vowels[5] = {'A', 'E', 'I', 'O', 'U'};
char cons[21] = {'B', 'C', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'M', 'N', 'P', 'Q', 'R', 'S', 'T', 'V', 'W', 'X', 'Y', 'Z'};

int dji(map<char, vector<char>>& graph, char dest, char source) {
    set<pair<int, char>> q;
    q.insert({0, source});
    set<char> seen;
    while (q.size() != 0) {
        /* printf("q = ["); */
        /* for (auto x : q) { */
        /*     printf("(%d %c) ", x.first, x.second); */
        /* } */
        /* printf("]\n"); */
        pair<int, char> p = *q.begin();
        q.erase(q.begin());
        int dist = p.first;
        char chr = p.second;
        if (chr == dest) {
            return dist;
        }
        seen.insert(chr);
        for (char child : graph[chr]) {
            if (seen.count(child) == 0) {
                q.insert({dist + 1, child});
            }
        }
    }
    return MAX;
}

void solve(int t) {
    string s;
    cin >> s;
    int n = s.size();
    map<char, vector<char>> graph;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 21; j++) {
            graph[vowels[i]].push_back(cons[j]);
            graph[cons[j]].push_back(vowels[i]);
        }
    }
    int answer = MAX;
    for (int i = 0; i < 26; i++) {
        int curr = 0;
        for (int j = 0; j < n; j++) {
            curr += dji(graph, 'A' + i, s[j]);
        }
        answer = min(answer, curr);
    }
    if (answer == MAX) {
        answer = -1;
    }
    printf("Case #%d: %d\n", t, answer);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
