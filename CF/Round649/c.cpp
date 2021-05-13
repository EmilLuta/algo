#include <bits/stdc++.h>

using namespace std;

int get_next(int current, set<int>& do_not_use) {
    while (do_not_use.count(current) != 0) {
        current++;
    }
    return current;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        if (a[i] > i + 1) {
            printf("-1\n");
            return 0;
        }
    }
    set<int> to_use;
    for (int i = 0; i <= 10 * 10 * 10 * 10 * 10; i++) {
        to_use.insert(i);
    }
    for (int i = 0; i < n; i++) {
        to_use.erase(a[i]);
    }
    vector<int> out(n);
    for (int i = 0; i < n; i++) {
        int current = *to_use.begin();
        out[i] = current;
        to_use.erase(current);
        if (i != n - 1 && a[i] != a[i + 1]) {
            to_use.insert(a[i]);
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", out[i]);
    }
    printf("\n");
}
