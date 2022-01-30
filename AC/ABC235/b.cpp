#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int answer = 0;
    bool done = false;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if (x <= answer) {
            done = true;
            continue;
        }
        if (!done && x > answer) {
            answer = x;
        }
    }
    printf("%d\n", answer);
}
