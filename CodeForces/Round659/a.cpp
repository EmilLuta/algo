#include <bits/stdc++.h>

using namespace std;

int main() {
    const int M = 200;
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        int n;
        scanf("%d", &n);
        string prev = "";
        for (int i = 0; i < M; i++) {
            prev += "a";
        }
        cout << prev << '\n';
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            string curr = "";
            for (int j = 0; j < x; j++) {
                curr += prev[j];
            }
            if (prev[x] == 'a') {
                curr += 'b';
            } else {
                curr += 'a';
            }
            for (int j = x + 1; j < M; j++) {
                curr += prev[j];
            }
            cout << curr << '\n';
            prev = curr;
        }
    }
}
