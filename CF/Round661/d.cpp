#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    string s;
    cin >> s;
    vector<int> answer(n);
    vector<int> needs_zero;
    vector<int> needs_one;
    int index = 1;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            if (s[i] == '0') {
                needs_one.push_back(index);
            } else {
                needs_zero.push_back(index);
            }
            answer[i] = index;
            continue;
        }
        if (s[i] == '0') {
            if ((int)needs_zero.size() == 0) {
                needs_one.push_back(++index);
                answer[i] = index;
            } else {
                int group = needs_zero.back();
                needs_zero.pop_back();
                answer[i] = group;
                needs_one.push_back(group);
            }
        } else {
            if ((int)needs_one.size() == 0) {
                needs_zero.push_back(++index);
                answer[i] = index;
            } else {
                int group = needs_one.back();
                needs_one.pop_back();
                answer[i] = group;
                needs_zero.push_back(group);
            }
        }
    }
    printf("%d\n", index);
    for (int i = 0; i < n; i++) {
        printf("%d ", answer[i]);
    }
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
