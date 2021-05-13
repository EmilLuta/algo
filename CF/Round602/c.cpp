#include <bits/stdc++.h>

using namespace std;

void compute_pref(vector<int> &pref, const vector<char> &s) {
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            if (s[i] == '(') {
                pref[i] = 1;
            } else {
                pref[i] = -1;
            }
            continue;
        }
        if (s[i] == '(') {
            pref[i] = pref[i - 1] + 1;
        } else {
            pref[i] = pref[i - 1] - 1;
        }
    }
}

void get_high_last_negative(vector<int> &pref, int &high_last_negative) {
    int n = pref.size();
    int high_negative = -1;
    for (int i = 0; i < n; i++) {
        if (pref[i] <= high_negative) {
            high_negative = pref[i];
            high_last_negative = i;
        }
    }
}

int get_zeros(vector<int> &pref) {
    int n = pref.size();
    int zeros = 0;
    for (int i = 0; i < n; i++) {
        if (pref[i] == 0) {
            zeros++;
        }
    }
    return zeros;
}

void get_swap_for_add(vector<int> &pref, int &i, int &j) {
    int n = pref.size();
    for (int k = 1; k < n; k++) {
        if (pref[k - 1] > pref[k] && pref[k] > 0) {
            i = k - 1;
            j = k;
            return;
        }
    }
}

void get_swap_for_remove(vector<int> &pref, int &i, int &j) {
    int n = pref.size();
    for (int k = 1; k < n; k++) {
        if (pref[k - 1] == 0 && k < n - 1) {
            i = k - 1;
            j = k;
            return;
        }
    }
}

int main() {
    int t_n;
    scanf("%d", &t_n);
    for (int t = 0; t < t_n; t++) {
        int n, k;
        scanf("%d %d", &n, &k);
        vector<char> s(n);
        vector<int> pref(n);
		vector<pair<int, int>> output;
        for (int i = 0; i < n; i++) {
            scanf(" %c", &s[i]);
        }
        compute_pref(pref, s);
        int high_last_negative = -1;
        get_high_last_negative(pref, high_last_negative);
        while (high_last_negative != -1) {
			swap(s[high_last_negative], s[high_last_negative + 1]);
            output.push_back({high_last_negative + 1, high_last_negative + 2});
            compute_pref(pref, s);
            high_last_negative = -1;
			get_high_last_negative(pref, high_last_negative);
        }
        /* printf("seg_faulting yet?\n"); */
        int zeros = get_zeros(pref);
        while (zeros != k) {
            /* printf("pref is :"); */
            /* for (int w = 0; w < n; w++) { */
                /* printf("%d ", pref[w]); */
            /* } */
            /* printf("\n"); */
            /* printf("seg_faulting in the first while loop\n"); */
            int i, j;
            if (zeros < k) {
                /* printf("smaller than k\n"); */
                get_swap_for_add(pref, i, j);
            } else {
                /* printf("bigger than k\n"); */
                get_swap_for_remove(pref, i, j);
            }
            /* printf("did a swap and didn't seg_fault\n"); */
            /* printf("%d, %d\n", i, j); */
            swap(s[i], s[j]);
            /* printf("horrible swap\n"); */
            output.push_back({i + 1, i + 2});
            /* printf("doing pushes\n"); */
            compute_pref(pref, s);
            zeros = get_zeros(pref);
            /* printf("computing pref\n"); */
        }
        /* printf("pref is: "); */
        /* for (int i : pref) { */
            /* printf("%d ", i); */
        /* } */
        /* printf("\n"); */
        /* printf("output is: "); */
        printf("%d\n", (int)output.size());
        for (pair<int, int> p : output) {
            printf("%d %d\n", p.first, p.second);
        }
    }
}
