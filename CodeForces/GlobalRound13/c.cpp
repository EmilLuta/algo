#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    long long answer = 0;
    vector<int> bounces(n, 0);
    for (int i = 0; i < n; i++) {
        int need = a[i] - bounces[i] - 1;
        if (need > 0) {
            bounces[i] += need;
            answer += need;
        }
        int outside = max(0, i + a[i] - n + 1);
        assert(outside <= a[i]);
        if (bounces[i] <= outside) {
            continue;
        }
        a[i] -= outside;
        bounces[i] -= outside;
        int j = i + a[i];
        while (j >= i + 2 && bounces[i] >= 1) {
            bounces[j]++;
            bounces[i]--;
            a[i]--;
            j--;
        }
        if(bounces[i] > 0 && i + 1 < n) {
            bounces[i + 1] += bounces[i];
        }
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
