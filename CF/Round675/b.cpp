#include <bits/stdc++.h>

using namespace std;

long long fix(vector<int>& a) {
    int n = a.size();
    sort(a.begin(), a.end());
    int x = a[n / 2];
    long long answer = 0;
    for (int i = 0; i < n; i++) {
        answer += abs(a[i] - x);
    }
    return answer;
}

void add(vector<vector<int>>& a, vector<int>& x, int r, int c) {
    if (a[r][c] != -1) {
        x.push_back(a[r][c]);
        a[r][c] = -1;
    }
}

void solve() {
    int h, w;
    scanf("%d%d", &h, &w);
    long long answer = 0;
    vector<vector<int>> a(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    int i = 0;
    int to_go = min((h + 1) / 2, (w + 1) / 2);
    while (i < to_go) {
        for (int to_c = 0; to_c < (w - i + 1) / 2; to_c++) {
            int c = i + to_c;
            vector<int> x;
            add(a, x, h - i - 1, w - c - 1);
            add(a, x, i, w - c - 1);
            add(a, x, i, c);
            add(a, x, h - i - 1, c);
            if ((int)x.size() > 0) {
                answer += fix(x);
            }
        }
        for (int to_r = 0; to_r < (h - i - 1) / 2; to_r++) {
            int r = i + 1 + to_r;
            vector<int> x;
            add(a, x, h - r - 1, w - i - 1);
            add(a, x, h - r - 1, i);
            add(a, x, r, i);
            add(a, x, r, w - i - 1);
            if ((int)x.size() > 0) {
                answer += fix(x);
            }
        }
        i++;
    }
    printf("%lld\n", answer);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
