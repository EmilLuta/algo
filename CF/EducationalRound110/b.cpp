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
    vector<int> odd;
    vector<int> even;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if (x % 2 == 0) {
            even.push_back(x);
        } else {
            odd.push_back(x);
        }
    }
    int answer = 0;
    int odd_n = odd.size();
    for (int i = 0; i < odd_n; i++) {
        for (int j = i + 1; j < odd_n; j++) {
            if (__gcd(odd[i], odd[j]) > 1) {
                answer++;
            }
        }
    }
    int taken = 0;
    for (int i = 0; i < (int)even.size(); i++) {
        answer += n - taken - 1;
        taken++;
    }
    printf("%d\n", answer);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
