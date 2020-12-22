#include<bits/stdc++.h>

using namespace std;

void update_counters(map<int, int> &counter, map<int, int> &rev_counter, int x, char sign) {
    if (sign == '+') {
        counter[x]++;
        if (counter[x] != 1) {
            rev_counter[counter[x] - 1]--;
            if (rev_counter[counter[x] - 1] == 0) {
                rev_counter.erase(counter[x] - 1);
            }
        }
        rev_counter[counter[x]]++;
    } else {
        counter[x]--;
        if (counter[x] == 0) {
            rev_counter[counter[x] + 1]--;
            if (rev_counter[counter[x] + 1] == 0) {
                rev_counter.erase(counter[x] + 1);
            }
        } else {
            rev_counter[counter[x]]++;
        }
    }
}

void solve(map<int, int> &rev_counter) {
    if (rev_counter[4]) {

    }
    return;
}

int main() {
    int n;
    scanf("%d", &n);
    map<int, int> counter;
    map<int, set<int>> rev_counter;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        update_counters(counter, rev_counter, x, '+');
    }
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        string s;
        cin >> s;
        char sign = s[0];
        cin >> s;
        int val = stoi(s);
        update_counter(counter, rev_counter, val, sign);
        solve(rev_counter);
    }
}
