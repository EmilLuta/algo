#include <bits/stdc++.h>

using namespace std;

# define deb_v(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << a[i] << " "; \
    cerr << ")\n";

# define deb(x) cerr << #x << " = " << x << "\n";

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", max(0, 2 * a + 100 - b));
}
