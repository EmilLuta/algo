#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    set<int> unvisited;
    for (int i = 1; i <= n; i++) {
        unvisited.insert(i);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        unvisited.erase(a[i]);
    }
    int last_used = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            a[i] = *unvisited.begin();
            int to_remove = a[i];
            if (a[i] == i + 1) {
                if (last_used != -1) {
                    swap(a[last_used], a[i]);
                    to_remove = a[last_used];
                } else {
                    a[i] = *next(unvisited.begin());
                    to_remove = a[i];
                }
            }
            last_used = i;
            unvisited.erase(to_remove);
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
