#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        string p, h;
        cin >> p >> h;
        if (p.size() > h.size()) {
            printf("NO\n");
            continue;
        }
        map<char, int> c;
        for (int i = 0; i < p.size(); i++) {
            c[p[i]]++;
        }
        for (int i = 0; i < p.size(); i++) {
            if (c[h[i]] == 1) {
                c.erase(h[i]);
                continue;
            }
            c[h[i]]--;
        }
        if (c.size() == 0) {
            printf("YES\n");
            continue;
        }
        bool found = false;
        for (int i = p.size(); i < h.size(); i++) {
            if (c[h[i]] == 1) {
                c.erase(h[i]);
            } else {
                c[h[i]]--;
            }
            if (c[h[i - p.size()]] == -1) {
                c.erase(h[i - p.size()]);
            } else {
                c[h[i - p.size()]]++;
            }
            if (c.size() == 0) {
                printf("YES\n");
                found = true;
                break;
            }
        }
        if (!found) {
            printf("NO\n");
        }
    }
}
