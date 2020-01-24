#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    set<string> s;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s.insert(a[i]);
    }
    long long output = 0;
    for (int i = 0; i < n; i++) {
        string fir = a[i];
        for (int j = i + 1; j < n; j++) {
            string sec = a[j];
            string third = "";
            for (int l = 0; l < k; l++) {
                if (fir[l] == sec[l]) {
                    third += fir[l];
                } else {
                    if ((fir[l] == 'S' && sec[l] == 'T') || (fir[l] == 'T' && sec[l] == 'S')) {
                        third += 'E';
                    } else if ((fir[l] == 'S' && sec[l] == 'E') || (fir[l] == 'E' && sec[l] == 'S')) {
                        third += 'T';
                    } else if ((fir[l] == 'E' && sec[l] == 'T') || (fir[l] == 'T' && sec[l] == 'E')) {
                        third += 'S';
                    }
                }
            }
            if (s.count(third) != 0) {
                output++;
            }
        }
    }
    printf("%lld\n", output / 3);
}
