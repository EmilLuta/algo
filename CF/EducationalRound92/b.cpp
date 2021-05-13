#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        int n, k, z;
        scanf("%d%d%d", &n, &k, &z);
        vector<int> a(n);
        map<int, int> m;
        vector<int> s(k + 3);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            m[a[i]] += 1;
            s[i + 1] = a[i] + s[i];
        }
        int answer = s[k + 1];
        /* printf("a = ["); */
        /* for (int i = 0; i < n; i++) { */
        /*     printf("%d ", a[i]); */
        /* } */
        /* printf("]\n"); */
        /* printf("s = ["); */
        /* for (int i = 0; i < k + 1; i++) { */
        /*     printf("%d ", s[i]); */
        /* } */
        /* printf("]\n"); */
        for (int i = 1; i < z; i++) {
            m[a[k - i + 1]] -= 1;
            if (m[a[k - i + 1]] == 0) {
                m.erase(a[k - i + 1]);
            }
            pair<int, int> last_value = *m.end();
            answer = max(answer, s[k - i + 2] + last_value.first);
        }
        printf("%d\n", answer);
    }
}
