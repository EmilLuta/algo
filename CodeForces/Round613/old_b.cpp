#include <bits/stdc++.h>

using namespace std;

void go(vector<int> &a, long long s, int n) {
    for (int i = 0; i < n; i++) {
        long long n_s = 0;
        for (int j = i; j < n; j++) {
            n_s += a[j];
            if (n_s >= s && (i != 0 || j != n - 1)) {
                printf("NO\n");
                return;
            }
        }
    }
    printf("YES\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        int n;
        scanf("%d", &n);
        vector<int> a(n);
        long long s = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            s += a[i];
        }
        bool all_zero = true;
        for (int i = 0; i < n; i++) {
            if (a[i] != 0) {
                all_zero = false;
                break;
            }
        }
        if (all_zero) {
            printf("NO\n");
            continue;
        }
        bool all_negative = true;
        for (int i = 0; i < n; i++) {
            if (a[i] > 0) {
                all_negative = false;
            }
        }
        if (all_negative) {
            printf("NO\n");
            continue;
        }
        long long n_s = 0, curr = 0;
        bool no = false;
        for (int i = 0; i < n; i++) {
            curr += a[i];
            if (n_s >= curr) {
                no = true;
                break;
            }
            if (curr <= 0) {
                no = true;
                break;
            }
            n_s = max(n_s, curr);
        }
        if (no) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }
}
