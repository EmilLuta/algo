#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        int n;
        scanf("%d", &n);
        vector<int> a(n);
        vector<int> c(n + 1, 0);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            c[a[i]] += 1;
        }
        int answer = 0;
        for (int i = 0; i < n; i++) {
            int s = a[i];
            for (int j = i + 1; j < n; j++) {
                s += a[j];
                if (s <= n) {
                    answer += c[s];
                    c[s] = 0;
                }
            }
        }
        printf("%d\n", answer);
    }
}
