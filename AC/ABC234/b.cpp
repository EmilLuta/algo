#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a[i].first, &a[i].second);
    }
    double answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long long x1 = a[i].first, x2 = a[j].first, y1 = a[i].second, y2 = a[j].second;
            long long x = abs(x1 - x2);
            long long y = abs(y1 - y2);
            double dist = sqrt(x * x + y * y);
            answer = max(answer, dist);
        }
    }
    printf("%lf\n", answer);
}
