#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int answer = 0;
    for (int i = 0; i < m; i++) {
        int x;
        scanf("%d", &x);
        answer += a[x - 1];
    }
    printf("%d\n", answer);
}
