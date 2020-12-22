#include <bits/stdc++.h>

using namespace std;

// ios::sync_with_stdio(0);
// cin.tie(0);

# define deb_v(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << a[i] << " "; \
    cerr << ")\n";

# define deb(x) cerr << #x << " = " << x << "\n";

void solve(int t) {
    int n, x;
    scanf("%d%d", &n, &x);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int answer = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            if (x > a[i]) {
                printf("-1\n");
                return;
            }
            int index = -1;
            for (int j = i; j >= 0; j--) {
                if (a[j] > x) {
                    index = j;
                }
            }
            if (index == -1) {
                printf("-1\n");
                return;
            }
            /* printf("swapped item %d at index %d with %d\n", a[index], index, x); */
            swap(a[index], x);
            answer++;
            for (int j = index + 1; j <= i - 1; j++) {
                if (x > a[j]) {
                    printf("-1\n");
                    return;
                }
                if (a[j] != a[j - 1] && a[j] != x) {
                    /* printf("swapped item %d at index %d with %d\n", a[j], j, x); */
                    swap(x, a[j]);
                    answer++;
                }
            }
        }
    }
    /* printf("%d ", a[0]); */
    /* for (int i = 1; i < n; i++) { */
    /*     printf("%d ", a[i]); */
    /*     if (a[i] < a[i - 1]) { */
    /*         printf("<problem_here> "); */
    /*     } */
    /* } */
    /* printf("\n"); */
    printf("%d\n", answer);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
