#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        int k;
        scanf("%d", &k);
        string s;
        cin >> s;
        int l = 0, m_l = 0;
        bool go = false;
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == 'A') {
                go = true;
                m_l = max(m_l, l);
                l = 0;
                continue;
            }
            if (go) {
                l++;
            }
        }
        m_l = max(m_l, l);
        printf("%d\n", m_l);
    }
}
