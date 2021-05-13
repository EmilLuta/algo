#include <bits/stdc++.h>

using namespace std;

int good(string& s, int start, int end, char c) {
    if (start == end) {
        if (c == s[start]) {
            return 0;
        }
        return 1;
    }
    int mid = (start + end) / 2;
    int half = end - mid;
    int left = good(s, start, mid, c + 1), right = good(s, mid + 1, end, c + 1);
    map<char, int> fix_left;
    map<char, int> fix_right;
    for (int i = start; i <= end; i++) {
        if (i <= mid) {
            fix_left[s[i]]++;
        } else {
            fix_right[s[i]]++;
        }
    }
    int l = half - fix_left[c];
    int r = half - fix_right[c];
    return min(left + r, right + l);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        int n;
        scanf("%d", &n);
        string s;
        cin >> s;
        printf("%d\n", good(s, 0, n - 1, 'a'));
    }
}
