#include <bits/stdc++.h>

using namespace std;

struct S {
    int s;
    int e;
    int c;
};

void solve() {
    int n;
    scanf("%d", &n);
    int start_split, end_split, start_both, end_both;
    long long cost_start_split, cost_end_split, cost_both;
    scanf("%d%d%lld", &start_both, &end_both, &cost_both);
    start_split = start_both;
    end_split = end_both;
    cost_start_split = cost_both;
    cost_end_split = cost_both;
    /* printf("both = (%d - %d --> %lld), split (%d - %d) --> %lld (%lld + %lld)\n", start_both, end_both, cost_both, start_split, end_split, cost_start_split + cost_end_split, cost_start_split, cost_end_split); */
    printf("%lld\n", cost_both);
    for (int i = 1; i < n; i++) {
        int new_start, new_end;
        long long new_cost;
        scanf("%d%d%lld", &new_start, &new_end, &new_cost);
        if (new_end - new_start > end_both - start_both) {
            cost_both = new_cost;
            start_both = new_start;
            end_both = new_end;
        } else if (new_end - new_start == end_both - start_both && new_cost < cost_both) {
            cost_both = new_cost;
            end_both = new_end;
            start_both = new_start;
        }
        if (new_start < start_split) {
            start_split = new_start;
            cost_start_split = new_cost;
        } else if (new_start == start_split) {
            cost_start_split = min(cost_start_split, new_cost);
        }
        /* printf("end_split = %d, cost_end_split = %lld, new_end = %d, new_cost = %lld\n", end_split, cost_end_split, new_end, new_cost); */
        if (end_split < new_end) {
            end_split = new_end;
            cost_end_split = new_cost;
        } else if (end_split == new_end) {
            cost_end_split = min(cost_end_split, new_cost);
        }
        long long both_range = end_both - start_both;
        long long split_range = end_split - start_split;
        /* printf("both = (%d - %d --> %lld), split (%d - %d) --> %lld (%lld + %lld)\n", start_both, end_both, cost_both, start_split, end_split, cost_start_split + cost_end_split, cost_start_split, cost_end_split); */
        if (both_range == split_range) {
            printf("%lld\n", min(cost_end_split + cost_start_split, cost_both));
        } else {
            printf("%lld\n", both_range < split_range ? cost_start_split + cost_end_split : cost_both);
        }
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
