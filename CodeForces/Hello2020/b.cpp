#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<vector<int>> s(n);
    map<int, int> mins;
    map<int, int> maxs;
    int ok = 0;
    for (int i = 0; i < n; i++) {
        int size;
        scanf("%d", &size);
        int minimum = INT_MAX;
        int maximum = INT_MIN;
        for (int j = 0; j < size; j++) {
            int x;
            scanf("%d", &x);
            minimum = min(minimum, x);
            maximum = max(maximum, x);
            s[i].push_back(x);
        }
        bool is_ok = false;
        for (int j = 1; j < size; j++) {
            if (s[i][j - 1] < s[i][j]) {
                is_ok = true;
                break;
            }
        }
        if (is_ok) {
            ok++;
        } else {
            mins[minimum]++;
            maxs[maximum]++;
        }
    }
    long long out = (long long)(n - ok) * ok * 2 + (long long)ok * (ok - 1) + ok;
    vector<int> max_v, min_v;
    for (pair<int, int> minimums : mins) {
        min_v.push_back(minimums.first);
    }
    for (pair<int, int> maximums : maxs) {
        max_v.push_back(maximums.first);
    }
    vector<int> pref_max;
    if ((int)max_v.size() == 0) {
    } else {
        pref_max.push_back(0);
        pref_max.push_back(maxs[max_v[0]]);
        for (int i = 1; i < (int)max_v.size(); i++) {
            pref_max.push_back(pref_max[i] + maxs[max_v[i]]);
        }
        for (int i = 0; i < (int)min_v.size(); i++) {
            auto max_index = upper_bound(max_v.begin(), max_v.end(), min_v[i]) - max_v.begin();
            out += (long long)mins[min_v[i]] * (pref_max[(int)max_v.size()] - pref_max[max_index]);
            /* } */
        }
    }
    printf("%lld\n", out);
}
