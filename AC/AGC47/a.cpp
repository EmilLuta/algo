#include <bits/stdc++.h>

using namespace std;

# define deb_v_p(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << "(" << item.first << ", " << item.second << ") "; \
    cerr << ")\n";

int pref[46][21];
int t_a_f[45][20];

pair<int, int> get_exp(long long a) {
    long long b = a;
    int twos = 0;
    int fives = 0;
    while (a > 0 && a % 2 == 0) {
        twos++;
        a /= 2;
    }
    while (b > 0 && b % 5 == 0) {
        fives++;
        b /= 5;
    }
    return {twos, fives};
}

int query(int two, int five) {
    return pref[45][20] + pref[two][five] - pref[two][20] - pref[45][five];
}

int main() {
    int n;
    scanf("%d", &n);
    long long mul = 1000000000;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        double x;
        scanf("%lf", &x);
        long long val = llround(x * mul);
        a[i] = get_exp(val);
        t_a_f[a[i].first][a[i].second]++;
    }
    for (int i = 1; i < 46; i++) {
        for (int j = 1; j < 21; j++) {
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
            pref[i][j] += t_a_f[i - 1][j - 1];
        }
    }
    long long answer = 0;
    for (int i = 0; i < n; i++) {
        int two = 18 - a[i].first;
        int five = 18 - a[i].second;
        answer += query(two, five);
        if (two <= 9 && five <= 9) {
            answer--;
        }
    }
    answer /= 2;
    printf("%lld\n", answer);
}
