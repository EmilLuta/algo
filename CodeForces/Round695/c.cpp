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

long long sum(vector<int>& a) {
    int n = a.size();
    long long answer = 0;
    for (int i = 0; i < n; i++) {
        answer += a[i];
    }
    return answer;
}

long long get_answer(vector<int>& a, vector<int>& b, vector<int>& c) {
    int min_b = b[0], min_c = c[0];
    long long s_a = sum(a), s_b = sum(b) - b[0], s_c = sum(c) - c[0];
    return s_a + max(s_b - min_c + s_c - min_b, max(min_b + s_b - min_c - s_c, min_c + s_c - min_b - s_b));
}

int main() {
    vector<int> n(3);
    scanf("%d%d%d", &n[0], &n[1], &n[2]);
    vector<vector<int>> a(3);
    for (int i = 0; i < 3; i++) {
        a[i] = vector(n[i], 0);
        a[i].resize(n[i]);
        for (int j = 0; j < n[i]; j++) {
            scanf("%d", &a[i][j]);
        }
        sort(a[i].begin(), a[i].end());
    }
    long long answer = 0;
    answer = max(answer, get_answer(a[0], a[1], a[2]));
    answer = max(answer, get_answer(a[1], a[0], a[2]));
    answer = max(answer, get_answer(a[2], a[0], a[1]));
    printf("%lld\n", answer);
}
