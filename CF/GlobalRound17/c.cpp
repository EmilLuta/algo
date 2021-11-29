#include <bits/stdc++.h>

using namespace std;

# define deb_v(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << item << " "; \
    cerr << ")\n";

# define deb(x) cerr << #x << " = " << x << "\n";

# define deb_v_p(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << "(" << item.first << ", " << item.second << ") "; \
    cerr << ")\n";

int N;

struct X {
    int left;
    int right;
    int val;

    int max_can_do() {
        return min(left, val - 1) + 1 + min(right, N - val);
    }
};

int bf(vector<int>& rich, vector<int>& poor) {
    for (int mask = 0; mask < (1 << N); mask++) {
        vector<int> x;
        for (int i = 0; i < N; i++) {
            if (((1 << i) & mask) != 0) {
                x.push_back(i);
            }
        }
        int n = x.size();
        for (int i_x = 0; i_x < n; i_x++) {
            int index = x[i_x];
            if (index[i_x]
        }
    }
}

int mine(vector<int>& rich, vector<int>& poor) {
    vector<X> a(N);
    for (int i = 0; i < N; i++) {
        a[i] = X{poor[i], rich[i], i + 1};
    }
    sort(a.begin(), a.end(), [](X& one, X &two) -> bool {
        return one.max_can_do() > two.max_can_do();
    });
    return 0;
}

/* void solve(int t) { */
/*     scanf("%d", &N); */
/*     vector<int> rich(N), poor(N); */
/*     vector<X> a(N); */
/*     for (int i = 0; i < N; i++) { */
/*         scanf("%d", &rich[i]); */
/*         scanf("%d", &poor[i]); */
/*         a[i] = X{poor[i], rich[i], i + 1}; */
/*     } */
/*     sort(a.begin(), a.end(), [](X& one, X &two) -> bool { */
/*         return one.max_can_do() > two.max_can_do(); */
/*     }); */
/*     for (int i = 0; i < N; i++) { */
/*         printf("we can have %d smaller than %d, and then %d bigger\n", a[i].left, a[i].val, a[i].right); */
/*     } */
/* } */

int main() {
    /* int t; */
    /* scanf("%d", &t); */
    /* for (int i = 1; i <= t; i++) { */
    /*     solve(i); */
    /* } */

}
