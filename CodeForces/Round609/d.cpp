#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        return 0;
    }
    int total = a[0] / 2;
    for (int i = 1; i < n; i++) {
        total += a[i] / 2;
        if ((a[i] % 2 == 1) && (a[i - 1] % 2 == 1)) {
            a[i]--;
            a[i - 1]--;
            total++;
        }
    }
    /* printf("%d\n", total); */
    vector<int> b(300001);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < a[i]; j++) {
            b[j]++;
        }
    }
    int x = min
    int total1 = b[0] / 2;
    for (int i = 1; i < (int)b.size(); i++) {
        total1 += b[i] / 2;
        if ((b[i] % 2 == 1) && (b[i - 1] % 2 == 1)) {
            b[i]--;
            b[i - 1]--;
            total1++;
        }
    }
    printf("%d\n", max(total, total1));
}
