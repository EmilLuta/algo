#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    map<int, set<int>> d;
    for (int i = 0; i < n; i++) {
        int x, c;
        scanf("%d%d", &x, &c);
        d[c].insert(x);
    }
    int prev_at = 0;
    long long answer = 0;
    for (pair<int, set<int>> p : d) {
        int end = *p.second.end();
        if (prev_at < end) {
            for (int x : p.second) {
                printf("from x = %d to -> x = %d for colour = %d\n", prev_at, x, p.first);
                answer += abs((long long)prev_at - x);
                prev_at = x;
            }
        } else {
            set<int>::reverse_iterator r_i;
            for (r_i = p.second.rbegin(); r_i != p.second.rend(); r_i++) {
                int x = *r_i;
                printf("from x = %d to -> x = %d for colour = %d\n", prev_at, x, p.first);
                answer += abs((long long)prev_at - x);
                prev_at = x;
            }
        }
    }
    printf("%lld\n", answer);
}
