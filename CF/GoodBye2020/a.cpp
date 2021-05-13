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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    set<float> areas;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            areas.insert(abs((float)(-a[i] + a[j]) / 2));
            areas.insert(abs((float)(-a[j] + a[i]) / 2));
        }
    }
    printf("%d\n", (int)areas.size());
    /* for (float x : areas) { */
    /*     printf("%f ", x); */
    /* } */
    /* printf("\n"); */
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}

/* (0, 1), (a[i], 0), (a[j], 0) */
