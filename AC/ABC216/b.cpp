#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    map<pair<string, string>, int> c;
    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;
        c[{a, b}] ++;
    }
    for (auto p : c) {
        if (p.second > 1) {
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
}
