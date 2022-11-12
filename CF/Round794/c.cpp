#include <bits/stdc++.h>

using namespace std;

int bw(vector<int>& a, int i) {
    int n = a.size();
    return a[(i - 1 + n) % n];
}

int fw(vector<int>& a, int i) {
    int n = a.size();
    return a[(i + 1) % n];
}

bool is_good(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        if (!((bw(a, i) < a[i] && a[i] > fw(a, i)) || (bw(a, i) > a[i] && a[i] < fw(a, i)))) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a.begin(), a.end());
    int left = 0;
    int right = n / 2;
    vector<int> out(n);
    int index = 0;
    while (left < n / 2 && right < n) {
        out[index] = a[left];
        left++;
        index++;
        out[index] = a[right];
        right++;
        index++;
    }
    if (right < n) {
        out[index] = a[right];
    }
    if (is_good(out)) {
        printf("YES\n");
        for (int i = 0 ; i < n; i++) {
            printf("%d ", out[i]);
        }
        printf("\n");
        return;
    }
    printf("NO\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        solve();
        t--;
    }
}
