#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e9 + 7;

bool can_do(vector<int>& a, int n, int k) {
    vector<int> b(a.begin(), a.end());
    for (int i = n - 1; i >= 2; i--) {
        if (b[i] < k) {
            return false;
        }
        int add = min(a[i], b[i] - k) / 3;
        b[i - 1] += add;
        b[i - 2] += add * 2;
    }
    return b[0] >= k && b[1] >= k;
}

void solve() {
    int n;
    scanf("%d", &n);
    vector<int> a(n), ch(n, 0);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int low = 0;
    int high = MAX;
    int answer = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (can_do(a, n, mid)) {
            answer = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    printf("%d\n", answer);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
