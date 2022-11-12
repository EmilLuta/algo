#include <bits/stdc++.h>

using namespace std;

void solve_1(vector<pair<int, int>>& vals) {
    int x, c;
    scanf("%d%d", &x, &c);
    vals.push_back({x, c});
}

int solve_2(vector<pair<int, int>>& vals, int i) {
    int c;
    scanf("%d", &c);
    long long out = 0;
    while (true) {
        if (vals[i].second <= c) {
            out += (long long)vals[i].first * vals[i].second;
            c -= vals[i].second;
            i++;
        } else {
            out += (long long)vals[i].first * c;
            vals[i].second -= c;
            c = 0;
        }
        if (c == 0) {
            break;
        }
    }
    printf("%lld\n", out);
    return i;
}

int main() {
    int n;
    scanf("%d", &n);
    int start = 0;
    vector<pair<int, int>> vals;
    for (int q = 0; q < n; q++) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            solve_1(vals);
        } else {
            start = solve_2(vals, start);
        }
    }
}
