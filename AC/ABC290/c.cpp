#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> a(n);
    set<int> s;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        s.insert(x);
    }
    int curr = 0;
    for (int x : s) {
        if (x == curr && k > 0) {
            curr++;
            k--;
            continue;
        }
        printf("%d\n", curr);
        return 0;
    }
    printf("%d\n", curr);
}
