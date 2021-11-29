#include <bits/stdc++.h>

using namespace std;

vector<int> a, tmp;

long long merge_sort(int start, int end) {
    if (end == start + 1) {
        return 0;
    }
    int mid = start + (end - start) / 2;
    long long inv = merge_sort(start, mid) + merge_sort(mid, end);
    int i = start, j = mid, k = start;
    while (i < mid && j < end) {
        if (a[i] <= a[j]) {
            tmp[k] = a[i];
            k++;
            i++;
        } else {
            tmp[k] = a[j];
            k++;
            j++;
            inv += mid - i;
        }
    }
    while (i < mid) {
        tmp[k] = a[i];
        k++;
        i++;
    }
    while (j < end) {
        tmp[k] = a[j];
        k++;
        j++;
    }
    for (int x = start; x < end; x++) {
        a[x] = tmp[x];
    }
    return inv;
}

void solve() {
    int n;
    scanf("%d", &n);
    a.resize(n, 0);
    tmp.resize(n, 0);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    long long answer = merge_sort(0, n);
    printf("%lld\n", answer);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
