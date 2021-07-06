#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, x;
    scanf("%d%d", &n, &x);
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }
    map<int, int> curr;
    map<int, int> prev;
    for (int coin : coins) {
        prev[coin] = 1;
    }
    int answer = 0;
    while (prev.size()) {
        for (pair<int, int> p : prev) {
            int val = p.first;
            int count = p.second;
            if (val == x) {
                answer += count;
                answer %= MOD;
                continue;
            }
            for (int coin : coins) {
                if (val + coin > x) {
                    continue;
                }
                curr[val + coin] += count;
                curr[val + coin] %= MOD;
            }
        }
        prev = curr;
        curr.clear();
        if (prev.size() == 0) {
            break;
        }
    }
    printf("%d\n", answer);
}
