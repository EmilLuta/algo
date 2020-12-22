#include <bits/stdc++.h>

using namespace std;

void get_w_and_answer(int n, string& s, int& answer, int& w) {
    char p = 'L';
    for (int i = 0; i < n; i++) {
        if (s[i] == 'W') {
            w++;
            answer++;
            if (p == 'W') {
                answer++;
            }
        }
        p = s[i];
    }
}

void get_gaps(map<int, vector<pair<int, int>>>& gaps, string& s) {
    int n = s.size();
    int prev_index = 0;
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'W') {
            if (found) {
                if (prev_index != 0) {
                    gaps[i - prev_index].push_back({prev_index, i - 1});
                }
                found = false;
            }
        } else {
            if (!found) {
                found = true;
                prev_index = i;
            }
        }
    }
}

void solve() {
    int n, k;
    scanf("%d%d", &n, &k);
    string s;
    cin >> s;
    int w = 0;
    int answer = 0;
    get_w_and_answer(n, s, answer, w);
    /* if (k == 0) { */
    /*     printf("%d\n", answer); */
    /*     return; */
    /* } */
    /* if (w == 0) { */
    /*     printf("%d\n", max(0, (k - 1) * 2) + 1); */
    /*     return; */
    /* } */
    /* if (w + k > n) { */
    /*     printf("%d\n", (n - 1) * 2 + 1); */
    /*     return; */
    /* } */
    /* if (w == 0) { */
    /*     printf("%d\n", (k - 1) * 2 + 1); */
    /*     return; */
    /* } */
    map<int, vector<pair<int, int>>> gaps;
    get_gaps(gaps, s);
    if ((int)gaps.size() == 0) {
        if (w == 0) {
            if (k == 0) {
                answer = 0;
            } else {
                answer += (k - 1) * 2 + 1;
            }
        } else {
            answer += min(n - w, k) * 2;
        }
    } else {
        for (auto gap_entry : gaps) {
            for (int i = 0; i < (int)gap_entry.second.size(); i++) {
                if (gap_entry.first <= k) {
                    answer += 2 * gap_entry.first + 1;
                    k -= gap_entry.first;
                    w += gap_entry.first;
                }
            }
        }
        answer += min(n - w, k) * 2;
    }
    /* printf("answer = %d\n", answer); */
    /* answer += min(n - w, k) * 2; */
    printf("%d\n", answer);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
