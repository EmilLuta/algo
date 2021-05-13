#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        int n, s;
        scanf("%d%d", &n, &s);
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        int i = 0, current = 0, m = 0, m_index = -1;
        while (i < n && current <= s) {
            current += a[i];
            if (m < a[i]) {
                m = a[i];
                m_index = i;
            }
            i++;
        }
        current -= m;
        bool more = false;
        while (i < n && current <= s) {
            current += a[i];
            more = true;
            i++;
        }
        if (more) {
            printf("%d\n", m_index + 1);
        } else {
            printf("0\n");
        }
    }
}
