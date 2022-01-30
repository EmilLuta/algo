#include <bits/stdc++.h>

using namespace std;

int m[16][16];
int n;

bool taken(int state, int i) {
    return state & (1 << i);
}

void take(int &state, int i) {
    state += 1 << i;
}

void go(int state, int start, int curr, int& answer) {
    if (start == n) {
        answer = max(answer, curr);
        return;
    }
    if (taken(state, start)) {
        go(state, start + 1, curr, answer);
        return;
    }
    for (int j = start + 1; j < n; j++) {
        if (!taken(state, j)) {
            int new_state = state;
            take(new_state, start);
            take(new_state, j);
            go(new_state, start + 1, curr ^ m[start][j], answer);
        }
    }
}

int main() {
    scanf("%d", &n);
    n *= 2;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            scanf("%d", &m[i][j]);
        }
    }
    int answer = 0;
    vector<pair<int, int>> what_i_have;
    go(0, 0, 0, answer);
    printf("%d\n", answer);
}
