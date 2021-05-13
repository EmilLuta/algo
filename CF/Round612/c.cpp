#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    set<int> odd_left, even_left;
    vector<vector<int>> gaps;
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) {
            odd_left.insert(i);
        } else {
            even_left.insert(i);
        }
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] % 2 == 1) {
            odd_left.erase(a[i]);
        } else {
            even_left.erase(a[i]);
        }
    }
    /* printf("odds left = "); */
    /* for (int i : odd_left) { */
    /*     printf("%d ", i); */
    /* } */
    /* printf("\n"); */
    /* printf("evens left = "); */
    /* for (int i : even_left) { */
    /*     printf("%d ", i); */
    /* } */
    /* printf("\n"); */
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            j++;
            continue;
        }
        if (j != 0) {
            int x = i - j;
            if (x == 0) {
                gaps.push_back({j * 100 + 1, x, i, j});
                j = 0;
                continue;
            }
            if (a[x - 1] % 2 == a[i] % 2) {
                gaps.push_back({j, x, i, j});
            } else {
                gaps.push_back({j * 10000 + 1, x, i, j});
            }
            j = 0;
        }
    }
    if (j != 0) {
        int i = n;
        int x = i - j;
        gaps.push_back({j * 100 + 1, x, i, j});
    }
    int n_gaps = gaps.size();
    sort(gaps.begin(), gaps.end());
    j = 0;
    while (j < (int)gaps.size()) {
        /* printf("gap size = %d\n", (int)gaps.size()); */
        vector<int> gap = gaps[j];
        bool use_odd = false, use_even = false;
        int x = gap[1];
        int i = gap[2];
        int d = gap[3];
        /* printf("rolling with gap [%d - %d; dist %d]\n", a[x - 1], a[i], d); */
        if (gap[1] == 0 && gap[2] == n) {
            use_odd = true;
        } else if (gap[1] == 0) {
            if (a[gap[2]] % 2 == 1) {
                use_odd = true;
                if ((int)odd_left.size() < d) {
                    if (j >= n_gaps) {
                        for (int k = gap[2] - 1; k >= 0; k--) {
                            if ((int)odd_left.size() != 0) {
                                int item = *odd_left.begin();
                                a[k] = item;
                                odd_left.erase(item);
                                i--;
                            } else {
                                break;
                            }
                        }
                    } else {
                        gaps.push_back(gap);
                        j++;
                        continue;
                    }
                }
            } else {
                use_even = true;
                if ((int)even_left.size() < d) {
                    if (j >= n_gaps) {
                        for (int k = gap[2] - 1; k >= 0; k--) {
                            if ((int)even_left.size() != 0) {
                                int item = *even_left.begin();
                                a[k] = item;
                                even_left.erase(item);
                                i--;
                            } else {
                                break;
                            }
                        }
                    } else {
                        gaps.push_back(gap);
                        j++;
                        continue;
                    }
                }
            }
        } else {
            if (a[gap[1] - 1] % 2 == 1) {
                use_odd = true;
                if (d > (int)odd_left.size() && j < n_gaps) {
                    gaps.push_back(gap);
                    j++;
                    continue;
                }
            } else {
                use_even = true;
                if (d > (int)even_left.size() && j < n_gaps) {
                    gaps.push_back(gap);
                    j++;
                    continue;
                }
            }
        }
        for (int k = x; k < i; k++) {
            if (use_odd) {
                if ((int)odd_left.size() != 0) {
                    int item = *odd_left.begin();
                    a[k] = item;
                    odd_left.erase(item);
                } else {
                    int item = *even_left.begin();
                    a[k] = item;
                    even_left.erase(item);
                }
            } else {
                if ((int)even_left.size() != 0) {
                    int item = *even_left.begin();
                    a[k] = item;
                    even_left.erase(item);
                } else {
                    int item = *odd_left.begin();
                    a[k] = item;
                    odd_left.erase(item);
                }
            }
        }
        j++;
        /* printf("Filled gap\n"); */
    }
    /* for (int i = 0; i < n; i++) { */
    /*     printf("%d ", a[i]); */
    /* } */
    /* printf("\n"); */
    int complexity = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] % 2 != a[i - 1] % 2) {
            complexity++;
        }
    }
    printf("%d\n", complexity);
}
