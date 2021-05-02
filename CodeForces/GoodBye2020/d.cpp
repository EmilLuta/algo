#include <bits/stdc++.h>

using namespace std;

// ios::sync_with_stdio(0);
// cin.tie(0);

# define deb_v(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << a[i] << " "; \
    cerr << ")\n";

# define deb(x) cerr << #x << " = " << x << "\n";

void solve(int t) {
    int n;
    scanf("%d", &n);
    long long answer = 0;
    vector<long long> w(n);
    vector<int> graph(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &w[i]);
        answer += w[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        graph[a]++;
        graph[b]++;
    }
    vector<long long> can_double;
    for (int i = 0; i < n; i++) {
        for (int times = 0; times < graph[i] - 1; times++) {
            can_double.push_back(w[i]);
        }
    }
    sort(can_double.begin(), can_double.end());
    reverse(can_double.begin(), can_double.end());
    vector<long long> pref(n, 0);
    for (int i = 1; i <= n - 2; i++) {
        pref[i] = pref[i - 1] + can_double[i - 1];
    }
    for (int i = 0; i < n - 1; i++) {
        printf("%lld ", pref[i] + answer);
    }
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
