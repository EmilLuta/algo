#include <bits/stdc++.h>

using namespace std;

int main() {
    int m;
    scanf("%d", &m);
    while (m > 0) {
        m--;
        int n, t, a, b, easy = 0, hard = 0;
        scanf("%d%d%d%d", &n, &t, &a, &b);
        vector<pair<int, int>> p(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &p[i].second);
            if (p[i].second == 0) {
                easy++;
            } else {
                hard++;
            }
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &p[i].first);
        }
        if ((long long)easy * a + (long long)hard * b <= (long long)t) {
            printf("%d\n", easy + hard);
            continue;
        }
        sort(p.begin(), p.end());
        long long time_left;
        int can_do_easy, to_add_easy, can_do_hard, to_add_hard, maximum = 0, mand_easy = 0, mand_hard = 0;
        time_left = p[0].first - 1;
        if (time_left >= 0) {
            can_do_easy = time_left / a;
            to_add_easy = min(can_do_easy, easy);
            time_left -= a * to_add_easy;
            maximum = to_add_easy;
        }
        if (time_left > 0) {
            can_do_hard = time_left / b;
            to_add_hard = min(can_do_hard, hard);
            maximum += to_add_hard;
        }
        if (p[0].second == 0) {
            mand_easy = 1;
        } else {
            mand_hard = 1;
        }
        for (int i = 1; i < n; i++) {
            /* printf("maximum = %d at %d\n", maximum, i - 1); */
            int current_max = 0;
            time_left = p[i].first - 1 - ((long long)mand_easy * a + (long long)mand_hard * b);
            /* printf("computing time_left = %d, as of p[i].first - 1 - (mand_easy * a + mand_hard * b) --- %d - 1 - (%d * %d + %d * %d)\n", time_left, p[i].first, mand_easy, a, mand_hard, b); */

            if (time_left >= 0) {
                can_do_easy = time_left / a;
                to_add_easy = min(can_do_easy, easy - mand_easy);
                time_left -= a * to_add_easy;
                current_max = to_add_easy + mand_easy + mand_hard;
            }
            if (time_left > 0) {
                can_do_hard = time_left / b;
                to_add_hard = min(can_do_hard, hard - mand_hard);
                current_max += to_add_hard;
            }
            if (p[i].second == 0) {
                mand_easy++;
            } else {
                mand_hard++;
            }
            /* printf("max = %d, curr_max = %d\n", maximum, current_max); */
            maximum = max(maximum, current_max);

        }
        printf("%d\n", maximum);
    }
}
