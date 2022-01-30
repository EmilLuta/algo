#include <bits/stdc++.h>

using namespace std;


# define deb_v(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << item << " "; \
    cerr << ")\n";

long long sum(long long n) {
    return (n + 1) * n / 2;
}

void solve() {
    int n;
    scanf("%d", &n);
    vector<long long> k(n), h(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &k[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &h[i]);
    }
    vector<long long> val_at(n, 0);
    for (int i = 0; i < n; i++) {
        val_at[i] = h[i];
        long long last_time = val_at[i];
        for (int j = i; j > 0; j--) {
            int time_diff = k[j] - k[j - 1];
            last_time -= time_diff;
            long long expected = last_time;
            if (expected <= 0) {
                break;
            }
            if (val_at[j - 1] > expected) {
                for (int x = j - 1; x < i; x++) {
                    int new_diff = k[x + 1] - k[x];
                    val_at[x + 1] = val_at[x] + new_diff;
                    val_at[x] = 0;
                }
                break;
            }
            if (val_at[j - 1] <= expected) {
                val_at[j - 1] = 0;
            }
        }
    }
    long long answer = 0;
    for (int i = 0; i < n; i++) {
        answer += sum(val_at[i]);
    }
    printf("%lld\n", answer);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
