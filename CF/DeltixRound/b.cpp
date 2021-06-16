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

struct line {
    int type, i, j;
};

void solve(int t) {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    vector<line> answer;
    for (int i = 0; i < n / 2; i++) {
        int j = n - i - 1;
        if (a[i] < a[j]) {
            a[i] += a[j];
            a[j] -= a[i];
            a[j] -= a[i];
            a[i] += a[j];
            answer.push_back(line{1, i + 1, j + 1});
            answer.push_back(line{2, i + 1, j + 1});
            answer.push_back(line{2, i + 1, j + 1});
            answer.push_back(line{1, i + 1, j + 1});
        } else {
            a[j] -= a[i];
            a[j] -= a[i];
            a[j] -= a[i];
            a[i] += a[j];
            answer.push_back(line{2, i + 1, j + 1});
            answer.push_back(line{2, i + 1, j + 1});
            answer.push_back(line{2, i + 1, j + 1});
            answer.push_back(line{1, i + 1, j + 1});
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    printf("%d\n", (int)answer.size());
    for (line l : answer) {
        printf("%d %d %d\n", l.type, l.i, l.j);
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
