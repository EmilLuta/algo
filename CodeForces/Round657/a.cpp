#include<bits/stdc++.h>

using namespace std;

int how_many(string& a) {
    int n = a.size();
    int c = 0;
    string f = "abacaba";
    for (int i = 0; i <= n - 7; i++) {
        bool ok = true;
        for (int j = 0; j < 7; j++) {
            if (a[i + j] != f[j]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            c++;
        }
    }
    return c;
}

void solve() {
    int n;
    scanf("%d", &n);
    string a;
    cin >> a;
    if (how_many(a) > 1) {
        printf("No\n");
        return;
    }
    string f = "abacaba";
    for (int i = 0; i <= n - 7; i++) {
        bool ok = true;
        for (int j = 0; j < 7; j++) {
            if (a[i + j] != f[j] && a[i + j] != '?') {
                ok = false;
                break;
            }
        }
        if (ok) {
            string new_s;
            for (int j = 0; j < n; j++) {
                new_s += a[j];
            }
            for (int j = 0; j < 7; j++) {
                new_s[i + j] = f[j];
            }
            if (how_many(new_s) == 1) {
                printf("Yes\n");
                for (int j = 0; j < n; j++) {
                    if (new_s[j] == '?') {
                        new_s[j] = 'z';
                    }
                }
                cout << new_s << endl;
                return;
            }
        }
    }
    printf("No\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}


/* "abacab?bacaba" */
