#include <bits/stdc++.h>

using namespace std;

bool verify(vector<char> a, int k, int n) {
    int ones = 0, zeros = 0;
    for (int i = 0; i < k; i++) {
        if (a[i] == '0') {
            zeros++;
        } else {
            ones++;
        }
    }
    if (ones != zeros) {
        return false;
    }
    for (int i = k; i < n; i++) {
        if (a[i - k] == '0') {
            zeros--;
        } else {
            ones--;
        }
        if (a[i] == '0') {
            zeros++;
        } else {
            ones++;
        }
        if (zeros != ones) {
            return false;
        }
    }
    return true;
}

bool fill_zeros(vector<char> a, int k, int n) {
    int ones = 0, zeros = 0, questions = 0;
    for (int i = 0; i < k; i++) {
        if (a[i] == '1') {
            ones++;
        } else if (a[i] == '0') {
            zeros++;
        } else {
            questions++;
        }
    }
    int mid = k / 2;
    if (ones > mid || zeros > mid) {
        return false;
    }
    for (int i = 0; i < k; i++) {
        if (a[i] == '?') {
            if (ones > zeros) {
                a[i] = '0';
                zeros++;
            } else {
                a[i] = '1';
                ones++;
            }
        }
    }
    for (int i = k; i < n; i++) {
        if (a[i - k] == '0') {
            zeros--;
        } else {
            ones--;
        }
        if (a[i] == '0') {
            zeros++;
        } else if (a[i] == '1') {
            ones++;
        } else {
            if (ones > zeros) {
                a[i] = '0';
                zeros++;
            } else {
                a[i] = '1';
                ones++;
            }
        }
        if (zeros != ones) {
            return false;
        }
    }
    return verify(a, n, k);
}

bool fill_z(vector<char> a, int k, int n) {
    bool ok = fill_zeros(a, k, n);
    reverse(a.begin(), a.end());
    return ok || fill_zeros(a, k, n);
}

bool fill_ones(vector<char> a, int k, int n) {
    int ones = 0, zeros = 0, questions = 0;
    for (int i = 0; i < k; i++) {
        if (a[i] == '1') {
            ones++;
        } else if (a[i] == '0') {
            zeros++;
        } else {
            questions++;
        }
    }
    int mid = k / 2;
    if (ones > mid || zeros > mid) {
        return false;
    }
    for (int i = 0; i < k; i++) {
        if (a[i] == '?') {
            if (zeros > ones) {
                a[i] = '1';
                ones++;
            } else {
                a[i] = '0';
                zeros++;
            }
        }
    }
    for (int i = k; i < n; i++) {
        if (a[i - k] == '0') {
            zeros--;
        } else {
            ones--;
        }
        if (a[i] == '0') {
            zeros++;
        } else if (a[i] == '1') {
            ones++;
        } else {
            if (zeros > ones) {
                a[i] = '1';
                ones++;
            } else {
                a[i] = '0';
                zeros++;
            }
        }
        if (zeros != ones) {
            return false;
        }
    }
    return verify(a, k, n);
}

bool fill_o(vector<char> a, int k, int n) {
    bool ok = fill_ones(a, k, n);
    reverse(a.begin(), a.end());
    return ok || fill_ones(a, k, n);
}

void solve() {
    int n, k;
    scanf("%d%d", &n, &k);
    string s;
    cin >> s;
    vector<char> a(s.begin(), s.end());
    if(fill_z(a, k, n) || fill_o(a, k, n)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        solve();
    }
}
