#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    vector<int> odd, even;
    for (int i = 1; i <= 2 * n; i++) {
        int x;
        scanf("%d", &x);
        if (x % 2 == 0) {
            even.push_back(i);
        } else {
            odd.push_back(i);
        }
    }
    if (even.size() == 0) {
        for (int i = odd.size() - 3; i >= 0; i -= 2) {
            printf("%d %d\n", odd[i], odd[i - 1]);
        }
        return;
    }
    if (odd.size() == 0) {
        for (int i = even.size() - 3; i >= 0; i -= 2) {
            printf("%d %d\n", even[i], even[i - 1]);
        }
        return;
    }
    if (even.size() % 2 == 0) {
        for (int i = even.size() - 3; i >= 0; i -= 2) {
            printf("%d %d\n", even[i], even[i - 1]);
        }
        for (int i = odd.size() - 1; i >= 0; i -= 2) {
            printf("%d %d\n", odd[i], odd[i - 1]);
        }
        return;
    }
    for (int i = even.size() - 2; i >= 0; i -= 2) {
        printf("%d %d\n", even[i], even[i - 1]);
    }
    for (int i = odd.size() - 2; i >= 0; i -= 2) {
        printf("%d %d\n", odd[i], odd[i - 1]);
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
