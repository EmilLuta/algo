#include <bits/stdc++.h>

using namespace std;

# define deb_v(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << item << " "; \
    cerr << ")\n";

# define deb(x) cerr << #x << " = " << x << "\n";

# define deb_v_p(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << "(" << item.first << ", " << item.second << ") "; \
    cerr << ")\n";

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int index = 0;
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        while (a[index] != s) {
            printf("No\n");
            index++;
        }
        printf("Yes\n");
        index++;
    }
}
