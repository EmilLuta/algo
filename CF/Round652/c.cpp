#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<long long> a(n);
    vector<int> w(k);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < k; i++) {
        scanf("%d", &w[i]);
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    sort(w.begin(), w.end());
    long long answer = 0;
    int current_index = 0;
    for (int i = 0; i < k; i++) {
        if (w[i] == 1) {
            answer += a[current_index];
        }
        answer += a[current_index];
        current_index++;
        w[i]--;
    }
    for (int i = 0; i < k; i++) {
        if (w[i] == 0) {
            continue;
        }
        answer += a[current_index + w[i] - 1];
        current_index += w[i];
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
