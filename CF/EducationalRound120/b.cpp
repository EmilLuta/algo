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

void solve(int t) {
    int n;
    scanf("%d", &n);
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }
    string s;
    cin >> s;
    vector<int> out(n);
    set<pair<int, int>> disliked, liked;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            disliked.insert({p[i], i});
        } else {
            liked.insert({p[i], i});
        }
    }
    int i = 1;
    for (pair<int, int> pp : disliked) {
        out[pp.second] = i;
        i++;
    }
    for (pair<int, int> pp : liked) {
        out[pp.second] = i;
        i++;
    }
    for (int x : out) {
        printf("%d ", x);
    }
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
