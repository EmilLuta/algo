#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    long long answer = 0;
    int c = a[0];
    for (int i = 1; i < n; i++) {
        c = max(c, a[i]);
        answer += c - a[i];
    }
    printf("%lld\n", answer);
}
