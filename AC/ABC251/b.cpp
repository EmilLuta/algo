#include <bits/stdc++.h>

using namespace std;

void add(vector<bool>& seen, int val, int w) {
    if (val <= w) {
        seen[val] = true;
    }
}

int main() {
    int n, w;
    scanf("%d%d", &n, &w);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<bool> seen(w + 1);
    for (int i = 0; i < n; i++) {
        add(seen, a[i], w);
        for (int j = i + 1; j < n; j++) {
            add(seen, a[j], w);
            add(seen, a[i] + a[j], w);
            for (int k = j + 1; k < n; k++) {
                add(seen, a[k], w);
                add(seen, a[k] + a[j], w);
                add(seen, a[k] + a[i], w);
                add(seen, a[i] + a[j] + a[k], w);
            }
        }
    }
    int answer = 0;
    for (int i = 0; i <= w; i++) {
        answer += seen[i];
    }
    cout << answer << endl;
}
