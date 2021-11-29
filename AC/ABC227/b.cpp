#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }
    int answer = 0;
    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int a = 1; a <= 150; a++) {
            for (int b = 1; b <= 150; b++) {
                int value = 3 * a + 2 * a * 2 * b + 3 * b;
                if (value == s[i]) {
                    found = true;
                }
            }
        }
        if (!found) {
            answer++;
        }
    }
    printf("%d\n", answer);
}
