#include <bits/stdc++.h>

using namespace std;

void test_case() {
    static char arr[1005];
    const string goal = "atcoder";
    scanf("%s", arr);
    string s(arr);
    int n = s.size();
    int m = goal.size();
    int ans = INT_MAX;
    for(int start = 0; start < n; ++start) {             //           v
        for(int to = 0; to <= min(start, m - 1); ++to) { // 0,1,2,3,4,5
            if(/*s[0..to-1] == goal[0..to-1] &&*/ s[start] > goal[to]) {
                ans = min(ans, start - to);
            }
            if(s[to] != goal[to]) {
                break;
            }
            if(n > m && to == m - 1) {
                printf("0\n");
                return;
            }
        }
    }
    if (ans == INT_MAX) {
        printf("-1\n");
        return;
    }
    printf("%d\n", ans);
}

int main(){
    /*
        1. Find if S is already bigger than atcoder. If yes, return 0.
        2. Find if this is possible. If not, return -1.
        3. 
    */
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        test_case();
    }
}
