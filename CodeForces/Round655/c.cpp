#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        int n;
        scanf("%d", &n);
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        int start = 0, end = n - 1;
        while (start < n && a[start] == start + 1) {
            start++;
        }
        if (start == n) {
            printf("0\n");
            continue;
        }
        while (end > -1 && a[end] == end + 1) {
            end--;
        }
        bool found = false;
        for (int i = start; i <= end; i++) {
            if (a[i] == i + 1) {
                found = true;
            }
        }
        if (found) {
            printf("2\n");
        } else {
            printf("1\n");
        }
    }
}
