#include <bits/stdc++.h>

using namespace std;

vector<int> bin(int x, int l) {
    vector<int> out(l, 0);
    int i = 0;
    while (x > 0) {
        out[i] = x % 2;
        x /= 2;
        i++;
    }
    reverse(out.begin(), out.end());
    return out;
}

int to_int(vector<int>& no, int l) {
    int out = 0;
    for (int i = 0; i < l; i++) {
        out = out * 2 + (no[i] <= 0 ? 0 : 1);
    }
    return out;
}

void solve() {
    int n, l;
    scanf("%d%d", &n, &l);
    vector<int> diff(l, 0);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        vector<int> x_bin = bin(x, l);
        for (int j = 0; j < l; j++) {
            if (x_bin[j] == 0) {
                diff[j]--;
            } else {
                diff[j]++;
            }
        }
    }
    printf("%d\n", to_int(diff, l));
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
