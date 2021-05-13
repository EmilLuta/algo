#include <bits/stdc++.h>

using namespace std;

bool is_good(long long x, int k) {
    vector<int> a;
    while (x != 0) {
        int y = x % 10;
        a.push_back(y);
        x /= 10;
    }
    int n = a.size();
    for (int i = 0; i < n / 2; i++) {
        int tmp = a[i];
        a[i] = a[n - i - 1];
        a[n - i - 1] = tmp;
    }
    for (int i = 0; i < k; i++) {
        for (int j = i + k; j < n; j += k) {
            if (a[j] != a[j - k]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    long long x;
    scanf("%lld", &x);
    while(!is_good(x, k)) {
        x++;
    }
    printf("%lld", x);
}
