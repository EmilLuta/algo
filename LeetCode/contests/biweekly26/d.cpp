#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int compare_tuples(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        if (n > m) {
            return 1;
        }
        if (m > n) {
            return -1;
        }
        for (int i = 0; i < n; i++) {
            if (a[i] > b[i]) {
                return 1;
            } else if (a[i] < b[i]) {
                return -1;
            }
        }
        return 0;
    }

    string largestNumber(vector<int>& costs, int target) {
        int n = 5001;
        vector<vector<int>> dp(n);
        for (int i = 0; i < (int)costs.size(); i++) {
            dp[costs[i]].push_back(i + 1);
        }
        for (int i = 0; i < target + 1; i++) {
            for (int j = 0; j <= (int)costs.size(); j++) {
                int cost = costs[j];
                if (i >= costs[j]) {
                    int curr_length = dp[i].size();
                    int new_dp_size = dp[i - cost].size();
                    if (new_dp_size > 0 && new_dp_size + 1 >= curr_length) {
                        vector<int> new_vector(dp[i]);
                        new_vector.push_back(j + 1);
                        sort(new_vector.begin(), new_vector.end());
                        if (compare_tuples(dp[i], new_vector) == -1) {
                            dp[i] = new_vector;
                        }
                    }
                }
            }
        }
        char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
        string out = "";
        for (int i = 0; i < (int)dp[target].size(); i++) {
            out += digits[dp[target][i]];
        }
        return out;
    }
};

int main() {
    Solution *s = new Solution();
    vector<int> input = {4,3,2,5,6,7,2,5,5};
    cout << s->largestNumber(input, 9) << endl;
}
