#include <bits/stdc++.h>

using namespace std;

int get_below(int node, vector<vector<int>>& child, vector<int>& val, vector<bool>& visited, long long& answer) {
    visited[node] = true;
    if ((int)child[node].size() == 0) {
        return val[node];
    }
    int mini = INT_MAX;
    for (int c : child[node]) {
        long long c_ans = get_below(c, child, val, visited, answer);
        if (c_ans < mini) {
            answer += mini == INT_MAX ? 0 : mini;
            mini = c_ans;
        } else {
            answer += c_ans;
        }
    }
    return max(mini == INT_MAX ? 0 : mini, val[node]);
}

void solve(int T) {
    int n;
    scanf("%d", &n);
    vector<int> val(n + 1);
    vector<int> parent(n + 1);
    vector<vector<int>> child(n + 1);
    vector<bool> visited(n + 1, false);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &val[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &parent[i]);
        child[parent[i]].push_back(i);
    }
    vector<int> starts;
    for (int i = 1; i <= n; i++) {
        if (parent[i] == 0) {
            starts.push_back(i);
        }
    }
    long long answer = 0;

    for (int start : starts) {
            int x = get_below(start, child, val, visited, answer);
            answer += x; // get_below(start, child, val, visited, answer);
    }
    printf("Case #%d: %lld\n", T, answer);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
