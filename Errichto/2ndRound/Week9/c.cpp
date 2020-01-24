#include <bits/stdc++.h>

using namespace std;

int find_divisor(int n, int start = 2) {
    for(int i = start; i * i <= n; i++) {
        if(n % i == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        int n;
        scanf("%d", &n);
        int a = find_divisor(n);
        if(a != -1) {
            n /= a;
            int b = find_divisor(n, a + 1);
            if(b != -1) {
                n /= b;
                int c = n;
                if(c != 1 && c != b && c != a) {
                    printf("YES\n%d %d %d\n", a, b, c);
                    continue;
                }
            }
        }
        printf("NO\n");
    }
}
