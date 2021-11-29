#include <bits/stdc++.h>

using namespace std;

long long power_10[19];

vector<int> get_digits(long long n) {
    vector<int> a(0);
    while (n != 0) {
        a.push_back(n % 10);
        n /= 10;
    }
    reverse(a.begin(), a.end());
    return a;
}

long long no_of_ones_to(long long x) {
    if (x < 10) {
        return x == 0 ? 0 : 1;
    }
    vector<int> dig = get_digits(x);
    int n = dig.size();
    long long answer = 0;
    long long tail = 0;
    if (n - 2 >= 0) {
        tail = (n - 1) * power_10[n - 2];
    }
    answer += tail; // case X[????]
    answer += (dig[0] - 1) * tail; // all cases [X????], where X < dig[0]
    if (dig[0] == 1) {
        long long left = 0;
        for (int i = 1; i < n; i++) {
            left = left * 10 + dig[i];
        }
        answer += left + 1; // all cases [1WXYZ]
    } else {
        answer += power_10[n - 1]; // all cases [1????]
    }
    long long last_no = 0;
    for (int i = 1; i < n; i++) {
        last_no = last_no * 10 + dig[i];
    }
    answer += no_of_ones_to(last_no);

    return answer;
}

int main() {
    power_10[0] = 1;
    for (int i = 1; i <= 18; i++) {
        power_10[i] = power_10[i - 1] * 10;
    }
    long long n;
    scanf("%lld", &n);
    long long left = 0;
    long long right = 1000000000000000000;
    long long answer = 1;
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        long long x = no_of_ones_to(mid);
        if (x <= n) {
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    printf("%lld\n", answer);
}
