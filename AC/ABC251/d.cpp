#include <bits/stdc++.h>

using namespace std;

int main() {
    /* int w; */
    /* cin >> w; */
    int w = 1e6;
    vector<int> a = {1, 2};
    for (int i = 4; i <= 1e6 * 2; i *= 2) {
        a.push_back(i - 1);
        a.push_back(i);
    }
    int n = a.size();
    set<int> seen;
    for (int i = 0; i < n; i++) {
        seen.insert(a[i]);
        for (int j = i + 1; j < n; j++) {
            seen.insert(a[j]);
            seen.insert(a[i] + a[j]);
            for (int k = j + 1; k < n; k++) {
                seen.insert(a[k]);
                seen.insert(a[j] + a[k]);
                seen.insert(a[i] + a[k]);
                seen.insert(a[i] + a[j] + a[k]);
            }
        }
    }
    for (int i = 1; i <= 1e6; i++) {
        if (seen.count(i) == 0) {
            cout << i << endl;
            return 0;
        }
    }
}
