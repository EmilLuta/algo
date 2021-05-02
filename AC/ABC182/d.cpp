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
    vector<long long> b(n);
    b[0] = a[0];
    long long s = a[0];
    long long max_so_far = max(0ll, s);
    long long answer = max_so_far;
    for (int i = 1; i < n; i++) {
        s += a[i];
        b[i] = b[i - 1] + s;
        max_so_far = max(max_so_far, s);
        if (i < n - 1) {
            answer = max(answer, b[i] + max_so_far);
        } else {
            answer = max(answer, b[i]);
        }
    }
    printf("%lld\n", answer);
}
