#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n), counter(n + 1);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);

    }
    int val = a[n - 1];
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            val = a[i];
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        if (val == a[i]) {
            continue;
        }
        printf("%d ", a[i]);
    }
    printf("\n");
}
