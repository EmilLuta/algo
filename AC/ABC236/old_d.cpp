#include <bits/stdc++.h>

using namespace std;

# define deb_v(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << item << " "; \
    cerr << ")\n";

# define deb(x) cerr << #x << " = " << x << "\n";

# define deb_v_p(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << "(" << item.first << ", " << item.second << ") "; \
    cerr << ")\n";

vector<int> cache(1 << 16);

void go(int state, vector<vector<int>>& m, int n, int curr, int& answer) {
    cache[state] = max(cache[state], curr);
    if (state == (1 << n) - 1) {
        answer = max(answer, curr);
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int pos_a = 1 << i;
            int pos_b = 1 << j;
            if ((state & pos_a) == 0 && (state & pos_b) == 0) {
                int new_state = state + pos_a + pos_b;
                if (cache[new_state] != -1) {
                    cache[state] = max(cache[state], m[i][j] ^ cache[new_state]);
                } else {
                    go(new_state, m, n, curr ^ m[i][j], answer);
                }
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    n *= 2;
    vector<vector<int>> m(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            scanf("%d", &m[i][j]);
        }
    }
    /* printf("done reading\n"); */
    for (int i = 0; i < (1 << 16); i++) {
        cache[i] = -1;
    }
    /* printf("m = ["); */
    /* for (int i = 0; i < n; i++) { */
    /*     printf("\t["); */
    /*     for (int j = 0; j < n; j++) { */
    /*         printf("%d ", m[i][j]); */
    /*     } */
    /*     printf("]\n"); */
    /* } */
    /* printf("\n"); */
    int answer = 0;
    go(0, m, n, 0, answer);
    printf("%d\n", answer);
}
