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

void read_input(vector<int>& a, int n, int& s) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        s += a[i];
    }
}

int answer = 0;

void go(vector<int> a1, vector<int> a2, vector<int> a3, int n1, int n2, int n3) {
    if (n1 + n2 + n3 == 1) {
        if (n1 == 1) {
            answer = max(answer, a1[0]);
        }
        if (n2 == 1) {
            answer = max(answer, a2[0]);
        }
        if (n3 == 1) {
            answer = max(answer, a3[0]);
        }
        return;
    }
    if (n1 != 0 && n2 != 0) {
        for (int i_1 = 0; i_1 < n1; i_1++) {
            for (int i_2 = 0; i_2 < n2; i_2++) {
                vector<int> new_a1(a1.begin(), a1.end());
                new_a1.erase(new_a1.begin() + i_1);
                a2[i_2] -= a1[i_1];
                go(new_a1, a2, a3, n1 - 1, n2, n3);
                a2[i_2] += a1[i_1];
            }
        }
        for (int i_2 = 0; i_2 < n2; i_2++) {
            for (int i_1 = 0; i_1 < n1; i_1++) {
                vector<int> new_a2(a2.begin(), a2.end());
                new_a2.erase(new_a2.begin() + i_2);
                a1[i_1] -= a2[i_2];
                go(a1, new_a2, a3, n1, n2 - 1, n3);
                a1[i_1] += a2[i_2];
            }
        }
    }
    if (n1 != 0 && n3 != 0) {
        for (int i_1 = 0; i_1 < n1; i_1++) {
            for (int i_3 = 0; i_3 < n3; i_3++) {
                vector<int> new_a1(a1.begin(), a1.end());
                new_a1.erase(new_a1.begin() + i_1);
                a3[i_3] -= a1[i_1];
                go(new_a1, a2, a3, n1 - 1, n2, n3);
                a3[i_3] += a1[i_1];
            }
        }
        for (int i_3 = 0; i_3 < n3; i_3++) {
            for (int i_1 = 0; i_1 < n1; i_1++) {
                vector<int> new_a3(a3.begin(), a3.end());
                new_a3.erase(new_a3.begin() + i_3);
                a1[i_1] -= a3[i_3];
                go(a1, a2, new_a3, n1, n2, n3 - 1);
                a1[i_1] += a3[i_3];
            }
        }
    }
    if (n2 != 0 && n3 != 0) {
        for (int i_2 = 0; i_2 < n2; i_2++) {
            for (int i_3 = 0; i_3 < n3; i_3++) {
                vector<int> new_a2(a2.begin(), a2.end());
                new_a2.erase(new_a2.begin() + i_2);
                a3[i_3] -= a2[i_2];
                go(a1, new_a2, a3, n1, n2 - 1, n3);
                a3[i_3] += a2[i_2];
            }
        }
        for (int i_3 = 0; i_3 < n3; i_3++) {
            for (int i_2 = 0; i_2 < n2; i_2++) {
                vector<int> new_a3(a3.begin(), a3.end());
                new_a3.erase(new_a3.begin() + i_3);
                a2[i_2] -= a3[i_3];
                go(a1, a2, new_a3, n1, n2, n3 - 1);
                a2[i_2] += a3[i_3];
            }
        }
    }
}

int main() {
    int n1, n2, n3, s = 0;
    scanf("%d%d%d", &n1, &n2, &n3);
    vector<int> a1(n1), a2(n2), a3(n3);
    read_input(a1, n1, s);
    read_input(a2, n2, s);
    read_input(a3, n3, s);
    go(a1, a2, a3, n1, n2, n3);
    printf("s = %d; answer = %d\n", s, answer);
}
