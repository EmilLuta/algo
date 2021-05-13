#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    map<int, int> counter;
    for (int i = 1; i <= n; i++) {
        int x = i;
        vector<int> out;
        counter[x]++;
        out.push_back(x);
        while (x != 0) {
            if (x % 2 == 1) {
                x--;
            } else {
                x /= 2;
            }
            counter[x]++;
            out.push_back(x);
        }
        printf("%d => ", i);
        for (int w : out) {
            printf("%d ", w);
        }
        printf("\n");
    }
    int correct = 1;
    for (pair<int, int> p : counter) {
        printf("%d => %d\n", p.first, p.second);
        if (p.second >= k) {
            correct = p.first;
        }
    }
    printf("%d\n", correct);
}
