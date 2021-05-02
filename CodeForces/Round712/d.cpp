#include <bits/stdc++.h>

using namespace std;

// ios::sync_with_stdio(0);
// cin.tie(0);

# define deb_v(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << item << " "; \
    cerr << ")\n";

# define deb(x) cerr << #x << " = " << x << "\n";

# define deb_v_p(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << "(" << item.first << ", " << item.second << ") "; \
    cerr << ")\n";

void print_assign_and_increase(int& r, int& c, int assigned, vector<vector<int>>& matrix, int n) {
    cout << assigned + 1 << " " << r + 1 << " " << c + 1 << "\n";
    cout.flush();
    /* printf("%d %d %d\n", r + 1, c + 1, assigned + 1); */
    matrix[r][c] = assigned + 1;
    c += 2;
    if (c >= n) {
        if (c % 2 == 1) {
            c = 0;
        } else {
            c = 1;
        }
        r++;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    vector<vector<int>> matrix(n, vector<int>(n));
    int r_0 = 0, c_0 = 0;
    int r_1 = 0, c_1 = 1;
    int assigned_0 = -1, assigned_1 = -1;
    for (int i = 0; i < n * n; i++) {
        /* printf("r_0 = %d, c_0 = %d, assigned_0 = %d, r_1 = %d, c_1 = %d, assigned_1 = %d\n", r_0, c_0, assigned_0, r_1, c_1, assigned_1); */
        int color;
        scanf("%d", &color);
        color--;
        if (assigned_0 == -1) {
            for (int c = 0; c < 3; c++) {
                if (c != color) {
                    assigned_0 = c;
                    break;
                }
            }
            print_assign_and_increase(r_0, c_0, assigned_0, matrix, n);
            continue;
        }
        if (assigned_1 == -1) {
            for (int c = 0; c < 3; c++) {
                if (c != color && c != assigned_0) {
                    assigned_1 = c;
                    break;
                }
            }
            print_assign_and_increase(r_1, c_1, assigned_1, matrix, n);
            continue;
        }
        if (color != assigned_0) {
            if (r_0 < n) {
                print_assign_and_increase(r_0, c_0, assigned_0, matrix, n);
                continue;
            }
            if (color != assigned_1) {
                print_assign_and_increase(r_1, c_1, assigned_1, matrix, n);
                continue;
            }
            int to_use = -1;
            for (int c = 0; c < 3; c++) {
                if (c != assigned_1 && c != assigned_0 && c != color) {
                    to_use = c;
                }
            }
            print_assign_and_increase(r_1, c_1, to_use, matrix, n);
            continue;
        }
        if (color != assigned_1) {
            if (r_1 < n) {
                print_assign_and_increase(r_1, c_1, assigned_1, matrix, n);
                continue;
            }
            if (color != assigned_0) {
                print_assign_and_increase(r_0, c_0, assigned_0, matrix, n);
                continue;
            }
            int to_use = -1;
            for (int c = 0; c < 3; c++) {
                if (c != assigned_1 && c != assigned_0 && c != color) {
                    to_use = c;
                }
            }
            print_assign_and_increase(r_0, c_0, to_use, matrix, n);
            continue;
        }
    }
    /* for (int i = 0; i < n; i++) { */
    /*     for (int j = 0; j < n; j++) { */
    /*         printf("%d ", matrix[i][j]); */
    /*     } */
    /*     printf("\n"); */
    /* } */
}
