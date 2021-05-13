#include <bits/stdc++.h>

using namespace std;

void compute_b_c(const vector<int>& a, vector<int>& b, vector<int>& c, const int n) {
    b[0] = 0;
    c[0] = a[0] - b[0];
    for (int i = 1; i < n; i++) {
        if (a[i] <= a[i - 1]) {
            b[i] = b[i - 1];
            c[i] = a[i] - b[i];
        } else {
            c[i] = c[i - 1];
            b[i] = a[i] - c[i];
        }
    }
    /* int target = (b[n - 1] +  c[0] + 1) / 2; */
    /* int rem_b = b[n - 1] - target; */
    /* int rem_c = c[0] - target; */
    /* for (int i = 0; i < n; i++) { */
    /*     b[i] -= rem_b; */
    /*     c[i] -= rem_c; */
    /* } */
    /* printf("a = ["); */
    /* for (int i = 0; i < n; i++) { */
    /*     printf("%d, ", a[i]); */
    /* } */
    /* printf("]\nb = ["); */
    /* for (int i = 0; i < n; i++) { */
    /*     printf("%d, ", b[i]); */
    /* } */
    /* printf("]\nc = ["); */
    /* for (int i = 0; i < n; i++) { */
    /*     printf("%d, ", c[i]); */
    /* } */
    /* printf("]\n"); */
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    compute_b_c(a, b, c, n);
    printf("answer = %d, b[n - 1] = %d, c[0] = %d\n", (b[n - 1] + c[0] + 1) / 2, b[n - 1], c[0]);
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int l, r, x;
        scanf("%d%d%d", &l, &r, &x);
        l--;
        r--;
        for (int i = l; i <= r; i++) {
            a[i] += x;
        }
        compute_b_c(a, b, c, n);
        printf("answer = %d, b[n - 1] = %d, c[0] = %d\n", (b[n - 1] + c[0] + 1) / 2, b[n - 1], c[0]);
    }
}
