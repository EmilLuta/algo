#include <bits/stdc++.h>

using namespace std;

int to_int(char a) {
    return (int)a;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    vector<char> s(n);
    for (int i = 0; i < n; i++) {
        scanf(" %c", &s[i]);
    }
    vector<char> b(n);
    for (int i = 0; i < k; i++) {
        b[i] = s[i];
    }
    for (int i = k; i < n; i++) {
        b[i] = b[i - k];
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (b[i] > s[i]) {
            break;
        }
        if (s[i] > b[i]) {
            ok = false;
            break;
        }
    }
    if (ok) {
        printf("%d\n", (int)b.size());
        for (int i = 0; i < n; i++) {
            printf("%c", b[i]);
        }
        printf("\n");
        return 0;
    }
    int i = k - 1;
    while (b[i] == '9') {
        b[i] = '0';
        i--;
        assert (i >= 0);
    }
    b[i] += 1;
    for (int i = k; i < n; i++) {
        b[i] = b[i - k];
    }
    printf("%d\n", (int)b.size());
    for (int i = 0; i < n; i++) {
        printf("%c", b[i]);
    }
    printf("\n");
}
