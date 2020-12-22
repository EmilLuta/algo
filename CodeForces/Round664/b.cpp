#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, s_r, s_c;
    scanf("%d%d%d%d", &n, &m, &s_r, &s_c);
    s_r--;
    s_c--;
    set<pair<int, int>> seen;
    vector<pair<int, int>> out;
    seen.insert({s_r, s_c});
    out.push_back({s_r, s_c});
    int last_c = s_c;
    for (int c = 0; c < m; c++) {
        if (c == s_c) {
            continue;
        }
        seen.insert({s_r, c});
        out.push_back({s_r, c});
        last_c = c;
    }
    if (s_r != 0) {
        out.push_back({0, last_c});
        seen.insert({0, last_c});
    }
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (r == s_r) {
                break;
            }
            pair<int, int> p = {r, c};
            if (seen.count(p) == 0) {
                seen.insert(p);
                out.push_back(p);
                last_c = c;
            }
        }
        if (r + 1 < n) {
            if (seen.count({r + 1, last_c}) != 0) {
                if (r + 2 < n) {
                    seen.insert({r + 2, last_c});
                    out.push_back({r + 2, last_c});
                    r++;
                }
            } else {
                seen.insert({r + 1, last_c});
                out.push_back({r + 1, last_c});
            }
        }
    }
    for (int i = 0; i < (int)out.size(); i++) {
        printf("%d %d\n", out[i].first + 1, out[i].second + 1);
    }
}
