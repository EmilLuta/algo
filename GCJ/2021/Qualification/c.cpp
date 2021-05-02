#include <bits/stdc++.h>

using namespace std;

void solve(int t) {
    int n, c;
    scanf("%d%d", &n, &c);
    if (c < n - 1 || c > n * (n + 1) / 2 - 1) {
        printf("Case #%d: IMPOSSIBLE\n", t);
        return;
    }
    c -= n - 1;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }
    int curr = 1;
    bool rev = false;
    int to_move = 2;
    int start = 0;
    int end = n - 1;
    while (c > 0) {
        c--;
        if (rev) {
            auto it = find(a.begin(), a.end(), to_move);
            a.erase(it);
            a.insert(a.begin() + end, to_move);
            to_move++;
            if (to_move > n) {
                rev = !rev;
                curr++;
                to_move = curr + 1;
                start++;
            }
        } else {
            auto it = find(a.begin(), a.end(), to_move);
            a.erase(it);
            a.insert(a.begin() + start, to_move);
            to_move++;
            if (to_move > n) {
                rev = !rev;
                curr++;
                to_move = curr + 1;
                end--;
            }
        }
    }
    printf("Case #%d: ", t);
    for (int i = 0; i < n; i++) {
        if (i != n - 1) {
            printf("%d ", a[i]);
        } else {
            printf("%d", a[i]);
        }
    }
    printf("\n");
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        solve(t);
    }
}

/*
5 4 3 2 1
1 2 3 4 5

2 4 5 3 1

1 3 5 4 2
1 2 4 5 3
1 2 3 5 4
1 2 3 4 5

5 + 4 + 3 + 2 = 5 * 6 / 2 - 1 = 14


4
1 2 3 4 5

5
2 1 3 4 5
2
1
1
1

6
3 2 1 4 5
3 + 1 + 1 + 1

7
4 3 2 1 5
4 + 1 + 1 + 1

8
5 4 3 2 1
5 + 1 + 1 + 1

9
5 4 2 3 1 = 0
1 3 2 4 5 = 5
1 2 3 4 5 = 7
1 2 3 4 5 = 8
1 2 3 4 5 = 9

10
5 2 3 4 1 = 0
1 4 3 2 5 = 5
1 2 3 4 5 = 8
1 2 3 4 5 = 9
1 2 3 4 5 = 10

11
5 2 4 3 1

12
2 4 3 5 1

13
2 5 4 3 1

14
2 4 5 3 1













1 2 3 4 5 = 4
2 1 3 4 5 = 5
3 2 1 4 5 = 6
4 3 2 1 5 = 7
5 4 3 2 1 = 8
5 4 2 3 1 = 9
5 2 3 4 1 = 10
2 3 4 5 1 = 11
2 4 3 5 1 = 12
2 5 4 3 1 = 13
2 4 5 3 1 = 14

11
5
1 2 3 4 5
5
2 1 3 4 5
5
3 2 1 4 5
5
4 3 2 1 5
5
5 4 3 2 1
5
5 4 2 3 1
5
5 2 3 4 1
5
2 3 4 5 1
5
2 4 3 5 1
5
2 5 4 3 1
5
2 4 5 3 1
*/
