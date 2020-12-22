#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int x;
    scanf("%d", &x);
    string answer(n, '2');
    for (int i = 0; i < n; i++) {
        if (i - x >= 0 && i + x < n) {
            if (answer[i - x] != '2' && s[i] != answer[i - x]) {
                printf("-1\n");
                printf("aici\n");
                for (int j = 0; j < n; j++) {
                    printf("%c", answer[j]);
                }
                printf("\n");
                printf("%d\n", i);
                return;
            }
            if (answer[i + x] != '2' && s[i] != answer[i + x]) {
                printf("-1\n");
                printf("sau aici\n");
                return;
            }
            answer[i - x] = s[i];
            answer[i + x] = s[i];
        } else if (i - x >= 0) {
            if (answer[i - x] != '2' && s[i] != answer[i - x]) {
                printf("-1\n");
                printf("poate aici\n");
                return;
            }
            answer[i - x] = s[i];
        } else if (i + x < n) {
            if (answer[i + x] != '2' && s[i] != answer[i + x]) {
                printf("-1\n");
                printf("aici???\n");
                return;
            }
            answer[i + x] = s[i];
        }
    }
    for (int i = 0; i < n; i++) {
        if (answer[i] == '2') {
            answer[i] = '0';
        }
    }
    if (n / 2 < x) {
        int left = n - x;
        for (int i = left; i < n - left; i++) {
            if (s[i] == '1') {
                printf("-1\n");
                printf("no se pueda\n");
                return;
            }
        }
    }
    cout << answer << endl;
    return;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
