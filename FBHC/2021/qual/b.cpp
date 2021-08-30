#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e9 + 7;

int dji(map<char, vector<char>>& graph, char dest, char source) {
    set<pair<int, char>> q;
    q.insert({0, source});
    set<char> seen;
    while (q.size() != 0) {
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
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        string x;
        cin >> x;
        graph[x[0]].push_back(x[1]);
    }
    long long answer = MAX;
    for (int i = 0; i < 26; i++) {
        long long curr = 0;
        for (int j = 0; j < n; j++) {
            curr += dji(graph, 'A' + i, s[j]);
        }
        answer = min(answer, curr);
    }
    if (answer >= MAX) {
        answer = -1;
    }
    printf("Case #%d: %lld\n", t, answer);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
