#include <bits/stdc++.h>

using namespace std;

// ios::sync_with_stdio(0);
// cin.tie(0);

# define deb_v(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << a[i] << " "; \
    cerr << ")\n";

# define deb(x) cerr << #x << " = " << x << "\n";

void solve(int t) {
    int w;
    scanf("%d", &w);
    vector<int> evens, odds;
    for (int i = 0; i < w; i++) {
        int x;
        scanf("%d", &x);
        if ((x & 1) == 0) {
            evens.push_back(x);
        } else {
            odds.push_back(x);
        }
    }
    sort(evens.begin(), evens.end());
    reverse(evens.begin(), evens.end());
    sort(odds.begin(), odds.end());
    reverse(odds.begin(), odds.end());
    bool alice_picks = true;
    int i = 0, j = 0;
    int n = evens.size(), m = odds.size();
    long long alice = 0, bob = 0;
    while (i < n || j < m) {
        if (alice_picks) {
            if (i < n && j < m) {
                if (evens[i] < odds[j]) {
                    j++;
                } else {
                    alice += evens[i];
                    i++;
                }
            } else if (i < n) {
                alice += evens[i];
                i++;
            } else {
                j++;
            }
        } else {
            if (i < n && j < m) {
                if (odds[j] < evens[i]) {
                    i++;
                } else {
                    bob += odds[j];
                    j++;
                }
            } else if (j < m) {
                bob += odds[j];
                j++;
            } else {
                i++;
            }
        }
        alice_picks = !alice_picks;
    }
    if (alice == bob) {
        printf("Tie\n");
    } else if (alice > bob) {
        printf("Alice\n");
    } else {
        printf("Bob\n");
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
