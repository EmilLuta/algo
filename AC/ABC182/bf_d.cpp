#include <bits/stdc++.h>

using namespace std;

# define deb_v(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << a[i] << " "; \
    cerr << ")\n";

# define deb(x) cerr << #x << " = " << x << "\n";

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    long long answer = 0, current = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            current += a[j];
            answer = max(answer, current);
        }
    }
    printf("%lld\n", answer);
}
