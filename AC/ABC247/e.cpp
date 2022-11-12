#include <bits/stdc++.h>

using namespace std;

void reset(int& a, int& b, int& c) {
    a = b = c = -1;
}

int main() {
    int n, x, y;
    scanf("%d%d%d", &n, &x, &y);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    long long answer = 0;
    int start = -1;
    int low = -1;
    int high = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] < y || a[i] > x) {
            reset(start, low, high);
            continue;
        }
        if (a[i] == y) {
            low = i;
        }
        if (a[i] == x) {
            high = i;
        }
        if (start == -1) {
            start = i;
        }
        if (low != -1 && high != -1) {
            answer += min(low, high) - start + 1;
        }
    }
    printf("%lld\n", answer);
}
