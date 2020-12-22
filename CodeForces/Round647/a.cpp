#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    int N = 65;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        long long a, b;
        scanf("%lld%lld", &a, &b);
        if (a < b) {
            swap(a, b);
        }
        bitset<65> a_b(a), b_b(b);
        int a_i = 0, b_i = 0;
        for (int i = 0; i < N; i++) {
            if (a_b[i] == 1) {
                a_i = i;
                break;
            }
        }
        for (int i = 0; i < N; i++) {
            if (b_b[i] == 1) {
                b_i = i;
                break;
            }
        }
        int a_start = a_i, b_start = b_i;
        bool ok = true;
        while (b_i < N) {
            if (a_b[a_i] != b_b[b_i]) {
                ok = false;
                break;
            }
            a_i++; b_i++;
        }
        if (!ok) {
            printf("-1\n");
            continue;
        }
        int to_cover = a_start - b_start;
        int answer = 0;
        for (int i = 3; i >= 1; i--) {
            answer += (to_cover / i);
            to_cover %= i;
        }
        printf("%d\n", answer);
    }
}
