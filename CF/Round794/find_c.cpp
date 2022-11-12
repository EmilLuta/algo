#include <bits/stdc++.h>

using namespace std;

int bw(vector<int>& a, int i) {
    int n = a.size();
    return a[(i - 1 + n) % n];
}

int fw(vector<int>& a, int i) {
    int n = a.size();
    return a[(i + 1) % n];
}

bool is_good(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        if (!((bw(a, i) < a[i] && a[i] > fw(a, i)) || (bw(a, i) > a[i] && a[i] < fw(a, i)))) {
            /* printf("not ok -- %d, %d, %d\n", bw(a, i), a[i], fw(a, i)); */
            return false;
        }
    }
    /* printf("wtf?\n"); */
    return true;
}

bool bf(vector<int> a) {
    int n = 0;
    sort(a.begin(), a.end());
    do {
        if (is_good(a)) {
            return true;
        }
    } while (next_permutation(a.begin(), a.end()));
    return false;
}

bool solve(vector<int>& a) {
    int n = a.size();
    sort(a.begin(), a.end());
    int left = 0;
    int right = n / 2;
    vector<int> out(n);
    int index = 0;
    while (left < n / 2 && right < n) {
        out[index] = a[left];
        left++;
        index++;
        out[index] = a[right];
        right++;
        index++;
    }
    if (right < n) {
        out[index] = a[right];
    }
    /* printf("proposed = ["); */
    /* for (int x : out) { */
    /*     printf("%d ", x); */
    /* } */
    /* printf("]\n"); */
    return is_good(out);

}

int main() {
    int rounds = 0;
    while (true) {
        int n = rand() % 10 + 1;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = rand() % 7;
        }
        if (bf(a) != solve(a)) {
            for (int i = 0; i < n; i++) {
                printf("%d ", a[i]);
            }
            printf("\n");
            printf("bf = %c, solve = %c", bf(a) ? 't' : 'f', solve(a) ? 't' : 'f');
            return 0;
        }
        rounds++;
        if (rounds % 100 == 0) {
            printf("rounds = %d\n", rounds);
        }
    }
    /* int t; */
    /* scanf("%d", &t); */
    /* while (t > 0) { */
    /*     t--; */
    /*     int n; */
    /*     scanf("%d", &n); */
    /*     vector<int> a(n); */
    /*     for (int i = 0; i < n; i++) { */
    /*         scanf("%d", &a[i]); */
    /*     } */
    /*     bool ok = solve(a); */
    /*     if (ok) { */
    /*         printf("Yes\n"); */
    /*     } else { */
    /*         printf("No\n"); */
    /*     } */
    /* } */
}
