#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;



int main() {
    int n, m = 0, a = 1, b = 1;
    scanf("%d", &n);
    string s;
    cin >> s;
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == ')') {
            c--;
        } else {
            c++;
        }
    }
    if (c != 0) {
        printf("0\n%d %d\n", a, b);
        return 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(s[i], s[j]);
            vector<int> pref(n, 0);
            pref[0] = 1;
            int min_no = 1;
            int min_no_count = 1;
            if (s[0] == ')') {
                pref[0] = -1;
                min_no = -1;
            }
            for (int k = 1; k < n; k++) {
                if (s[k] == ')') {
                    pref[k] = pref[k - 1] - 1;
                    if (pref[k] < min_no) {
                        min_no = pref[k];
                        min_no_count = 0;
                    }
                } else {
                    pref[k] = pref[k - 1] + 1;
                }
                if (pref[k] == min_no) {
                    min_no_count++;
                }
            }
            if (min_no_count > m) {
                m = min_no_count;
                a = i;
                b = j;
            }
            swap(s[i], s[j]);
        }
    }
    printf("%d\n%d %d", m, a + 1, b + 1);
}
