#include <bits/stdc++.h>

using namespace std;

// ios::sync_with_stdio(0);
// cin.tie(0);

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
    string a, b;
    cin >> a >> b;
    int j = 0;
    vector<int> shortest(m);
    for (int i = 0; i < m; i++) {
        while (b[i] != a[j]) {
            j++;
        }
        shortest[i] = j;
        j++;
    }
    int answer = shortest[m - 1] - shortest[m - 2];
    int x = m - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (x == 0) {
            break;
        }
        if (a[i] == a[shortest[x]]) {
            answer = max(answer, i - shortest[x - 1]);
            x--;
        }
    }
    printf("%d\n", answer);
}
