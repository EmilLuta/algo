#include <bits/stdc++.h>

using namespace std;

const long long MAX = 111111111111111111;

long long to_number(vector<int>& a) {
    int n = a.size();
    long long no = 0;
    for (int i = 0; i < n; i++) {
        no = no * 10 + a[i];
    }
    return no;
}

long long try_with(long long n, long long target) {
    long long answer = MAX;
    for (int diff = -9; diff <= 9; diff++) {
        vector<int> a(n);
        for (int start_d = 1; start_d <= 9; start_d++) {
            int index = 0;
            int d = start_d;
            while (index < n && 0 <= d && d <= 9) {
                a[index] = d;
                index++;
                d += diff;
            }
            if (index == n) {
                long long no = to_number(a);
                if (no >= target) {
                    answer = min(answer, no);
                }
            }
        }
    }
    return answer;
}

int main() {
    long long x;
    scanf("%lld", &x);
    long long initial = x;
    vector<int> a;
    while (x > 0) {
        a.push_back(x % 10);
        x /= 10;
    }
    long long n = a.size();
    long long answer = min(try_with(n, initial), try_with(n + 1, initial));
    printf("%lld\n", answer);
}
