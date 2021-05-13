#include <bits/stdc++.h>

using namespace std;

// ios::sync_with_stdio(0);
// cin.tie(0);

# define deb_v(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << item << " "; \
    cerr << ")\n";

# define deb(x) cerr << #x << " = " << x << "\n";

# define deb_v_p(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << "(" << item.first << ", " << item.second << ") "; \
    cerr << ")\n";

long long const MAX = 1000000000000000;

void solve(int t) {
    int n;
    scanf("%d", &n);
    vector<int> cost(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &cost[i]);
    }
    long long answer = MAX;
    vector<pair<long long, int>> x(n, {MAX, MAX});
    x[0] = {(long long)cost[0] * n, cost[0]};
    long long x_sum = cost[0];
    for (int i = 1; i < n; i++) {
        if (i % 2 == 0) {
            long long old = x[i - 1].first - x[i - 1].second + cost[i];
            long long newer = x_sum + (long long)(n - i / 2) * cost[i];
            if (old >= newer) {
                x[i] = {newer, cost[i]};
            } else {
                x[i] = {old, x[i - 1].second};
            }
            x_sum += cost[i];
        } else {
            x[i] = x[i - 1];
        }
    }
    for (int i = 0; i < n; i++) {
        /* printf("X = shortest path using segments up to %d will cost you %lld\n", i, x[i].first); */
    }
    vector<pair<long long, int>> y(n, {MAX, MAX});
    y[1] = {(long long)cost[1] * n, cost[1]};
    long long y_sum = cost[1];
    for (int i = 2; i < n; i++) {
        if (i % 2 == 1) {
            long long old = y[i - 1].first - y[i - 1].second + cost[i];
            long long newer = y_sum + (long long)(n - i / 2) * cost[i];
            if (old >= newer) {
                y[i] = {newer, cost[i]};
            } else {
                y[i] = {old, y[i - 1].second};
            }
            y_sum += cost[i];
        } else {
            y[i] = y[i - 1];
        }
    }
    for (int i = 0; i < n; i++) {
        /* printf("Y = shortest path using segments up to %d will cost you %lld\n", i, y[i].first); */
    }
    for (int i = 0; i < n; i++) {
        /* printf("if we use up to i = %d, we got %lld cost on x and %lld cost on y\n", i, x[i].first, y[i].first); */
        answer = min(answer, x[i].first + y[i].first);
    }
    printf("%lld\n", answer);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
