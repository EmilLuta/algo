/*
https://atcoder.jp/contests/agc048/tasks/agc048_a
*/

#include <bits/stdc++.h>

using namespace std;

bool lexicographically_bigger(const string& a, const string& b) {
    int n = a.size();
    int m = b.size();
    for (int i = 0; i < min(n, m); i++) {
        if (a[i] > b[i]) {
            return true;
        } else if(a[i] < b[i]) {
            return false;
        }
    }
    return n > m;
}

void test_case() {
    static char arr[1005];
    const string goal = "atc";
    scanf("%s", arr);
    string s(arr);
    int n = s.size();
    int m = goal.size();
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] != 'a') {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("-1\n");
        return;
    }
    if (lexicographically_bigger(s, goal)) {
        printf("0\n");
        return;
    }
    if (s[index] > 't') {
        printf("%d\n", index - 1);
    } else {
        printf("%d\n", index);
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        test_case();
    }
}
