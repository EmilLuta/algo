#include <bits/stdc++.h>

using namespace std;

vector<int> lis(vector<int>& a) {
    vector<int> dp;
    map<int, int> prev;
    for (int x : a) {
        int ge_index = lower_bound(dp.begin(), dp.end(), x) - dp.begin();
        if (ge_index != 0) {
            prev[x] = dp[ge_index - 1];
        }
        if (ge_index == (int)dp.size()) {
            dp.push_back(x);
        } else {
            dp[ge_index] = x;
        }
    }
    vector<int> sequence(dp.size());
    int val = dp[(int)dp.size() - 1];
    int index = (int)dp.size() - 1;
    while (prev.count(val) != 0) {
        sequence[index] = val;
        index--;
        val = prev[val];
    }
    sequence[0] = val;
    return sequence;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    vector<int> lis_seq = lis(a);
    for (int x : lis_seq) {
        printf("%d ", x);
    }
    printf("\n");
}
