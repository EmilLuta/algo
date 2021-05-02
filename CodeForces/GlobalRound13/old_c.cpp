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
        if (a[i] > 1) {
            answer += a[i] - 1;
            for (int j = min(n - 1, i + a[i]); j > i + 1; j--) {
                int k = j;
                while (k < n) {
                    int next_k = k + a[k];
                    a[k] = max(a[k] - 1, 1);
                    k = next_k;
                }
            }
            a[i] = 1;
            printf("a = ");
            for (int x = 0; x < n; x++) {
                printf("%d ", a[x]);
            }
            printf("\n");
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

