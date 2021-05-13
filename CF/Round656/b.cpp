#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        int n;
        scanf("%d", &n);
        vector<int> a(2 * n);
        for (int i = 0; i < 2 * n; i++) {
            scanf("%d", &a[i]);
        }
        vector<int> answer(n);
        set<int> seen;
        int index = 0;
        for (int i = 0; i < 2 * n; i++) {
            if (seen.count(a[i]) == 0) {
                seen.insert(a[i]);
                answer[index] = a[i];
                index++;
            }
        }
        for (int i = 0; i < n; i++) {
            printf("%d ", answer[i]);
        }
        printf("\n");
    }
}
