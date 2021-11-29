#include <bits/stdc++.h>

using namespace std;

# define deb_v(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << item << " "; \
    cerr << ")\n";

# define deb(x) cerr << #x << " = " << x << "\n";

# define deb_v_p(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << "(" << item.first << ", " << item.second << ") "; \
    cerr << ")\n";

bool remove(vector<int>& a, int n, int x) {
    int left = 0, right = n - 1;
    while (left < right) {
        if (a[left] != a[right]) {
            if (a[left] == x) {
                left++;
                continue;
            }
            if (a[right] == x) {
                right--;
                continue;
            }
            return false;
        }
        left++;
        right--;
    }
    return true;
}

void solve(int t) {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int left = 0, right = n - 1;
    vector<int> candidates;
    while (left < right) {
        if (a[left] != a[right]) {
            candidates.push_back(a[left]);
            candidates.push_back(a[right]);
            break;
        }
        left++;
        right--;
    }
    if (candidates.size() == 0) {
        printf("YES\n");
        return;
    }
    for (int x : candidates) {
        if (remove(a, n, x)) {
            printf("YES\n");
            return;
        }
    }
    printf("NO\n");
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
