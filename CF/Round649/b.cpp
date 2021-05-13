#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int start = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) {
            start = i - 1;
            break;
        }
    }
    if (start == n - 1) {
        printf("%d%d\n", a[start], a[start]);
        return;
    }
    bool increasing = a[start] < a[start + 1];
    vector<int> v;
    for(int i = start + 1; i < n; i++) {
        if (increasing) {
            if (a[i] < a[i - 1]) {
                increasing = false;
                v.push_back(a[start]);
                start = i - 1;
            }
        } else {
            if (a[i] > a[i - 1]) {
                increasing = true;
                v.push_back(a[start]);
                start = i - 1;
            }
        }
    }
    if (start != n - 1) {
        v.push_back(a[start]);
    }
    v.push_back(a[n - 1]);
    printf("%d\n", v.size());
    for (int i = 0; i < (int)v.size(); i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
