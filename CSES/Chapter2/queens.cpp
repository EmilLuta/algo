#include <bits/stdc++.h>

using namespace std;

#define deb(x) cerr << #x << " = ("; \
    for (int i = 0; i < 16; i++) cerr << x[i] << " "; \
    cerr << ")\n";

/*
col =
0 1 2 3
0 1 2 3
0 1 2 3
0 1 2 3

diag1 =
0 1 2 3
1 2 3 4
2 3 4 5
3 4 5 6

diag2 =
3 4 5 6
2 3 4 5
1 2 3 4
0 1 2 3
*/

int counter = 0;
int n = 16;
int col[16], diag1[16 + 16], diag2[16 + 16];

void search(int y) {

    if (y == n) {
        counter++;
        return;
    }
    for (int x = 0; x < n; x++) {
        if (col[x] == 1 || diag1[x + y] == 1 || diag2[x - y + n - 1] == 1) {
            continue;
        }
        col[x] = diag1[x + y] = diag2[x - y + n - 1] = 1;
        search(y + 1);
        col[x] = diag1[x + y] = diag2[x - y + n - 1] = 0;
    }
}

int main() {
    search(0);
    printf("%d\n", counter);
}
