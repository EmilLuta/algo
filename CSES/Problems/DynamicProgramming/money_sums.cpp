#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    set<int> s, prev_s;
    for (int i = 0; i < n; i++) {
        s.insert(a[i]);
        for (int x : prev_s) {
            s.insert(x);
            s.insert(x + a[i]);
        }
        prev_s = s;
        s.clear();
    }
    prev_s.erase(0);
    printf("%d\n", (int)prev_s.size());
    for (int x : prev_s) {
        printf("%d ", x);
    }
    printf("\n");
}
