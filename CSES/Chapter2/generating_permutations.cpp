#include <bits/stdc++.h>

using namespace std;

void go(int k, vector<int>& permutation, vector<int>& chosen) {
    if (k == (int)permutation.size()) {
        printf("permutation = {");
        for (int i = 0; i < k; i++) {
            printf("%d, ", permutation[i]);
        }
        printf("}\n");
        return;
    }
    for (int i = 1; i <= k; i++) {
        if (chosen[i]) {
            continue;
        }
        permutation.push_back(i);
        chosen[i] = true;
        go(k, permutation, chosen);
        permutation.pop_back();
        chosen[i] = false;
    }
}

int main() {
    vector<int> permutation;
    vector<int> chosen(4, false);
    go(3, permutation, chosen);
}
