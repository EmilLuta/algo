#include <bits/stdc++.h>

using namespace std;

void go(int k, vector<int>& subsets, int current) {
    int n = subsets.size();

    if (current == k + 1) {
        printf("subset = {");
        for (int i = 0; i < n; i++) {
            printf("%d ", subsets[i]);
        }
        printf("}\n");
        return;
    }
    subsets.push_back(current);
    go(k, subsets, current + 1);
    subsets.pop_back();
    go(k, subsets, current + 1);
}

int main() {
    vector<int> subsets;
    go(3, subsets, 1);
}
