#include <bits/stdc++.h>

using namespace std;

int to_binary(int x) {
    int m = 1;
    int answer = 0;
    while (x != 0) {
        answer += m * (x % 2);
        x /= 2;
        m *= 10;
    }
    return answer;
}

int main() {
    int n, x;
    scanf("%d%d", &n, &x);
    vector<int> weight(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &weight[i]);
    }
    vector<pair<int, int>> best(1 << n, {1, 0});
    // for every subset
    for (int s = 1; s < (1 << n); s++) {
        best[s] = {n + 1, 0};
        // for every element that can belong to the set
        for (int p = 0; p < n; p++) {
            // if he's in this subset
            if (s & (1 << p)) {
                // try to understand if this is the optimal guy to add last in a cart
                pair<int, int> option = best[s ^ (1 << p)];
                if (option.second + weight[p] <= x) {
                    option.second += weight[p];
                } else {
                    option.first++;
                    option.second = weight[p];
                }
                best[s] = min(best[s], option);
                /* printf("Move from %d to %d, we can go from (%d %d) to (%d %d)\n", to_binary(s ^ (1 << p)), to_binary(s), best[s^(1<<p)].first, best[s^(1<<p)].second, option.first, option.second); */
            }
        }
    }
    printf("%d\n", best[(1 << n) - 1].first);
}
