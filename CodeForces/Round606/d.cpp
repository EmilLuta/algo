#include <bits/stdc++.h>

using namespace std;

string reverse(string s) {
    int n = s.size();
    for (int i = 0; i < n / 2; i++)  {
        swap(s[i], s[n - i - 1]);
    }
    return s;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        int n;
        scanf("%d", &n);
        vector<string> a(n);
        set<string> s;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            s.insert(a[i]);
        }
        int z_z = 0, o_o = 0, z_o = 0, o_z = 0, rev_z_o = 0, rev_o_z = 0;
        for (int i = 0; i < n; i++) {
            int w_n = a[i].size();
            if (a[i][0] == '0' && a[i][w_n - 1] == '0') {
                o_o = 0;
            }
            if (a[i][0] == '0') {
                start_zero += 1;
                string w = reverse(a[i]);
                if (s.count(w) == 0) {
                    can_reverse_zero = 0
                }
            } else {
                start_one += 1;
            }
            if (a[i][(int)a[i].size() - 1] == '0') {
                end_zero += 1;
            } else {
                end_zero += 1;
            }
        }
    }
}
