#include <bits/stdc++.h>

using namespace std;

int erase(int left, int right, string s, char c) {
    int erased = 0;
    while (left < right) {
        if (s[left] != s[right]) {
            if (s[left] == c) {
                left++;
                erased++;
            } else if (s[right] == c) {
                right--;
                erased++;
            } else {
                return -1;
            }
        } else {
            left++;
            right--;
        }
    }
    return erased;
}

void solve() {
    int n;
    scanf("%d", &n);
    string s;
    cin >> s;
    if (n == 1) {
        printf("0\n");
        return;
    }
    set<char> chars(s.begin(), s.end());
    int answer = 1e9;
    for (char c : chars) {
        int erased = erase(0, n - 1, s, c);
        if (erased != -1) {
            answer = min(answer, erased);
        }
    }
    if (answer == 1e9) {
        printf("-1\n");
        return;
    }
    printf("%d\n", answer);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        solve();
        t--;
    }
}
