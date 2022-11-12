#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), [](const string& l, const string& r) -> bool {
        return l.size() < r.size();
    });
    int answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            string x = a[i];
            string y = a[j];
            int len_y = y.size();
            int i_y = 0;
            string xx(x.begin(), x.end());
            string yy = "";
            while (i_y < len_y && x[0] != y[i_y]) {
                i_y++;
            }
            if (i_y < len_y) {
                yy += y[i_y];
            }
            while (((int)x.size() == 1 && i_y + 1 < len_y) || (i_y + 1 < len_y && x[1] != y[i_y + 1])) {
                i_y++;
            }
            for (int ii_y = i_y + 1; ii_y < len_y; ii_y++) {
                yy += y[ii_y];
            }
            if (xx == yy) {
                answer++;
            }
            cout << "Trying to match '" << x << "' and '" << y << "' by removing from '" << y << "'\n";
            cout << "My match: x = '" << xx << "'; y = '" << yy << "'\n";
        }
    }
    printf("%d\n", answer);
}
