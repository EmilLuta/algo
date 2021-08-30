#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]);
    }
    make_heap(h.begin(), h.end());
    int answer = 0;
    while (k > 0) {
        int x = h.front();
        if (x == 0) {
            break;
        }
        answer += x;
        pop_heap(h);
        push_heap(h, x - 1);
    }
}
