#include <bits/stdc++.h>

using namespace std;

int in_length(int len, int k) {
    return len / (k + 1);
}

void solve() {
    int n, k;
    scanf("%d%d", &n, &k);
    string s;
    cin >> s;
    int first_one = -1, last_one = -1;
    for(int i = 0; i < n; i++) {
        if (s[i] == '1') {
            first_one = i;
            break;
        }
    }
    if (first_one == -1) {
        if (n == k) {
            printf("1\n");
            return;
        }
        printf("%d\n", 1 + (n - 1) / (k + 1));
        return;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '1') {
            last_one = i;
            break;
        }
    }
    int answer = 0;
    answer += in_length(n - 1 - last_one, k);
    answer += in_length(first_one, k);
    int start = first_one;
    for (int i = first_one + 1; i <= last_one; i++) {
        if (s[i] == '1') {
            answer += (i - start - 1) / (2 * k + 1);
            start = i;
        }
    }
    printf("%d\n", answer);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
