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
    vector<int> score(n, 0);
    int wins = (n - 1) / 2;
    int ties = (n - 1) % 2;
    int each = wins * 3 + ties;
    vector<int> answer;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (score[i] <= each - 3) {
                score[i] += 3;
                answer.push_back(1);
            } else if (score[i] == each - 1) {
                score[i] += 1;
                score[j] += 1;
                answer.push_back(0);
            } else {
                score[j] += 3;
                answer.push_back(-1);
            }
        }
    }
    for (int x : answer) {
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
