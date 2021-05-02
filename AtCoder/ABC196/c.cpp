#include <bits/stdc++.h>

using namespace std;

int to_power(int a, int n) {
    int answer = 1;
    for (int i = 0; i < n; i++) {
        answer *= a;
    }
    return answer;
}

int main() {
    string s;
    cin >> s;
    int len = s.size();
    int answer = 0;
    for (int i = 2; i < len; i += 2) {
        int to_fill = i / 2;
        answer += 9 * to_power(10, to_fill - 1);
    }
    int half = len / 2;
    if (len % 2 == 1) {
        printf("%d\n", answer);
        return 0;
    }
    int current = 0;
    int multiplier = 1;
    for (int i = half - 1; i >= 0; i--) {
        if (i == 0) {
            current += multiplier * (s[i] - '0' - 1);
        } else {
            current += multiplier * (s[i] - '0');
        }
        multiplier *= 10;
    }
    string last = "";
    for (int i = 0; i < len; i++) {
        last += s[i % half];
    }
    if (last <= s) {
        current++;
    }
    answer += current;
    printf("%d\n", answer);
}
