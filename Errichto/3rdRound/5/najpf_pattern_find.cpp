// https://www.spoj.com/problems/NAJPF/
// https://www.spoj.com/status/ns=26336146

#include <bits/stdc++.h>

using namespace std;

int P = 1e9 + 7;
int B = 29;
const int MAX_N = 1e6 + 1;
int pref[MAX_N];
int pre_power[MAX_N];

int mul(int a, int b) {
    return (long long) a * b % P;
}

int sub(int a, int b) {
    int answer = (a - b) % P;
    if (answer < 0) answer += P;
    return answer;
}

int sum(int a, int b) {
    return (a + b) % P;
}

bool eq(int h, int L, int R) {
    return mul(h, pre_power[L]) == sub(pref[R], pref[L]);
}

int main() {
    int t;
    scanf("%d", &t);
    vector<int> value_for_char(26);
    for (int i =  0; i < 26; i++) {
        value_for_char[i] = rand();
    }
    pre_power[0] = 1;
    for (int i = 1; i < MAX_N; i++) {
        pre_power[i] = mul(pre_power[i - 1], B);
    }
    while (t > 0) {
        t--;
        string s, p;
        cin >> s;
        cin >> p;
        int n = s.size(), m = p.size();
        for (int i = 0; i < n; i++) {
            pref[i + 1] = sum(pref[i], mul(value_for_char[s[i] - 'a'], pre_power[i]));
        }
            int hash_for_p = 0;
        for (int i = 0; i < m; i++) {
            hash_for_p = sum(hash_for_p, mul(value_for_char[p[i] -'a'], pre_power[i]));
        }
        vector<int> out;
        for (int i = m; i < n + 1; i++) {
            if (eq(hash_for_p, i - m, i)) {
                out.push_back(i - m + 1);
            }
        }
        int n_out = out.size();
        if (n_out == 0) {
            printf("Not Found\n");
            continue;
        }
        printf("%d\n", n_out);
        for (int i = 0; i < n_out; i++) {
            printf("%d ", out[i]);
        }
        printf("\n");
    }
}
