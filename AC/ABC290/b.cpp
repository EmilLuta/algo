#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'o' && k > 0) {
            printf("o");
            k--;
            continue;
        }
        printf("x");
    }
    printf("\n");
}
