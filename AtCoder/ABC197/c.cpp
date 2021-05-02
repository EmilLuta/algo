#include <bits/stdc++.h>

using namespace std;

vector<vector<vector<int>>> combinations;

void go(vector<int>& a, vector<vector<int>>& current_config, vector<int> current, int i) {
    int n = a.size();
    if (i == n) {
        current_config.push_back(current);
        combinations.push_back(current_config);
        current_config.pop_back();
        return;
    }
    current_config.push_back(current);
    go(a, current_config, {a[i]}, i + 1);
    current_config.pop_back();
    current.push_back(a[i]);
    go(a, current_config, current, i + 1);
    current.pop_back();
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    vector<vector<int>> current_config;
    go(a, current_config, {a[0]}, 1);
    int answer = INT_MAX;
    for (vector<vector<int>> config : combinations) {
        int xor_config = 0;
        for (vector<int> group : config) {
            int or_group = 0;
            for (int no : group) {
                or_group |= no;
            }
            xor_config ^= or_group;
        }
        answer = min(answer, xor_config);
    }
    printf("%d\n", answer);
}
