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
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        map<int, vector<int>> m;
        for (int i = 0; i < n; i++) {
            int x = a[i];
            int c = 0;
            while (x % 2 == 0) {
                x /= 2;
                c += 1;
            }
            m[x].push_back(c);
        }
        int out = 0;
        for (pair<int, vector<int>> key_value : m) {
            vector<int> value = key_value.second;
            int maximum = 0;
            for (int i = 0; i < (int)value.size(); i++) {
                maximum = max(maximum, value[i]);
            }
            out += maximum;
        }
        printf("%d\n", out);
    }
}
