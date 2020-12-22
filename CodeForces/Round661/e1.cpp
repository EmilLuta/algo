#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    long long s;
    scanf("%d%lld", &n, &s);
    /* map<int, pair<int, long long>> graph; */
    map<long long, int> counter;
    long long current = 0;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        long long w;
        scanf("%d%d%lld", &a, &b, &w);
        current += w;
        counter[w]++;
        /* graph[a].push_back({b, w}); */
        /* graph[b].push_back({a, w}); */
    }
    long long answer = 0;
    while (current > s) {
        pair<long long, int> k_v = *counter.rbegin();
        long long w = k_v.first / 2;
        current -= k_v.first - w;
        counter[k_v.first]--;
        counter[w]++;
        if (k_v.second == 1) {
            counter.erase(k_v.first);
        }
        answer++;
    }
    printf("%lld\n", answer);
    /* map<int, pair<int, long long>> tree; */
    /* vector<int> q = {1}; */
    /* int index = 0; */
    /* while (index < (int)q.size()) { */
    /*     int node = q[index]; */
    /*     index++; */
    /*     for (pair<int, long long> child : graph[node]) { */
    /*         tree[node].push_back(child); */
    /*         q.push_back(child.first); */
    /*     } */
    /* } */
    /* vector<pair<int, long long>> qq = {1, 0}; */
    /* index = 0; */
    /* while (index < (int)qq.size()) { */
    /*     pair<int, long long> node = q[index]; */
    /*     index++; */
    /* } */
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
