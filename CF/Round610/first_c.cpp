#include <bits/stdc++.h>

using namespace std;

int main() {
    int m;
    scanf("%d", &m);
    while (m > 0) {
        m--;
        int n, t, a, b, easy = 0, hard = 0;
        scanf("%d %d %d %d", &n, &t, &a, &b);
        vector<pair<int, int>> p(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &p[i].second);
            if (p[i].second == 0) {
                easy++;
                continue;
            }
            hard++;
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &p[i].first);
        }
        sort(p.begin(), p.end());
        int maximum = 0, at_time = 0, mand_easy = 0, mand_hard = 0;
        for (int i = 0; i < n - 1; i++) {
            if (p[i].second == 0) {
                at_time += a;
                mand_easy++;
            } else {
                at_time += b;
                mand_hard++;
            }
            int time_left = p[i + 1].second - 1 - (mand_hard * b + mand_easy * a);
            printf("time_left = %d\n", time_left);
            if (time_left >= 0) {
                maximum = mand_easy + mand_hard;
                int easy_left = easy - mand_easy;
                int can_do_easy = time_left / a;
                int extra_easy = min(easy_left, can_do_easy);
                maximum += extra_easy;
                time_left -= extra_easy * a;
            }
            if (time_left > 0) {
                int hard_left = hard - mand_hard;
                int can_do_hard = time_left / b;
                int extra_hard = min(hard_left, can_do_hard);
                maximum += extra_hard;
            }
        }
        printf("%d\n", maximum);
    }
}
