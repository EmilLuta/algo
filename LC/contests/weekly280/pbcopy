#include <bits/stdc++.h>

using namespace std;

struct TestCase {
    vector<int> vec;
    int slots;
    int answer;
};

class Solution {
public:
    void self_max(int& a, int b) {
        a = max(a, b);
    };

    int maximumAndSum(vector<int>& nums, int numSlots) {
        int const MAX = 11;
        vector<int> three_pow(MAX, 1);
        for (int i = 1; i < MAX; i++) {
            three_pow[i] = 3 * three_pow[i - 1];
        }
        int n = 1;
        for (int i = 1; i <= numSlots; i++) {
            n *= 3;
        }
        vector<int> dp(n, 0);
        for (int num : nums) {
            vector<int> new_dp(n);
            for (int m = 0; m < n; m++) {
                for (int i = 0; i < numSlots; i++) {
                    int val = m / three_pow[i] % 3;
                    if (val < 2) {
                        int new_state = m + three_pow[i];
                        self_max(new_dp[new_state], dp[m] + (num & (i + 1)));
                    }
                }
            }
            dp = new_dp;
        }
        int answer = 0;
        for (int x : dp) {
            answer = max(answer, x);
        }
        return answer;
    }
};

int main() {
    Solution sol = Solution();
    vector<TestCase> test_cases = {
        TestCase {{1, 2, 3, 4, 5, 6}, 3, 9},
        TestCase {{1, 3, 10, 4, 7, 1}, 9, 24}
    };
    for (TestCase tc : test_cases) {
        assert(sol.maximumAndSum(tc.vec, tc.slots) == tc.answer);
    }
}


1, 2, 3, 4, 5, 6

_ _ _ _ _ _ _ _ _

"0122110"

000
001
002
010
011
...
222



100 -> 200
    -> 110
    -> 101
