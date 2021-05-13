#include <bits/stdc++.h>

using namespace std;

int me(int n, vector<int>& a) {
    int longest_monotonic = 0;
    int current = 0;
    int c = 0;
    bool increasing = true;
    for (int i = 1; i < n; i++) {
        if (increasing) {
            if (a[i] > a[i - 1]) {
                current++;
            } else {
                if (longest_monotonic == current) {
                    c++;
                } else if (longest_monotonic < current) {
                    c = 1;
                    longest_monotonic = current;
                }
                current = 1;
                increasing = false;
            }
        } else {
            if (a[i] < a[i - 1]) {
                current++;
            } else {
                if (longest_monotonic == current) {
                    c++;
                } else if (longest_monotonic < current) {
                    c = 1;
                    longest_monotonic = current;
                }
                current = 1;
                increasing = false;
            }
        }
        if (a[i] > a[i - 1]) {
            increasing = true;
        }
    }
    if (longest_monotonic == current) {
        c++;
    } else if (longest_monotonic < current) {
        c = 1;
        longest_monotonic = current;
    }
    if (c != 2) {
        return 0;
    }
    for (int i = 0; i < n; i++) {
        int max_dist = 0;
        for (int d = 1; i - d >= 0 && i + d < n; d++) {
            if (a[i - d] < a[i - d + 1] && a[i + d] < a[i + d - 1]) {
                max_dist = d;
            } else {
                break;
            }
        }
        /* printf("max_dist = %d, longest_monotonic = %d\n", max_dist, longest_monotonic); */
        if (max_dist == longest_monotonic) {
            return 1;
        }
    }
    return 0;
}

int bf(int n, vector<int>& a) {
    int longest_monotonic = 0;
    int current = 0;
    bool increasing = true;
    set<int> peaks;
    for (int i = 1; i < n; i++) {
        if (increasing) {
            if (a[i] > a[i - 1]) {
                current++;
            } else {
                if (longest_monotonic == current) {
                    peaks.insert(i - 1);
                } else if (longest_monotonic < current) {
                    peaks = {i - 1};
                    longest_monotonic = current;
                }
                current = 1;
                increasing = false;
            }
        } else {
            if (a[i] < a[i - 1]) {
                current++;
            } else {
                if (longest_monotonic == current) {
                    peaks.insert(i - longest_monotonic - 1);
                } else if (longest_monotonic < current) {
                    peaks = {i - longest_monotonic - 1};
                    longest_monotonic = current;
                }
                current = 1;
                increasing = false;
            }
        }
        if (a[i] > a[i - 1]) {
            increasing = true;
        }
    }
    if (longest_monotonic == current) {
        if (increasing) {
            peaks.insert(n - 1);
        } else {
            peaks.insert(n - current - 1);
        }
    } else if (longest_monotonic < current) {
        if (increasing) {
            peaks = {n - 1};
        } else {
            peaks = {n - current - 1};
        }
        longest_monotonic = current;
    }
    /* printf("peak no = %d\n", (int)peaks.size()); */
    /* for (int x : peaks) { */
    /*     printf("peak = %d\n", x); */
    /* } */
    /* printf("longest = %d\n", longest_monotonic); */
    if ((int)peaks.size() != 1) {
        return 0;
    }
    for (int i = 0; i < n; i++) {
        int max_dist = 0;
        for (int d = 1; i - d >= 0 && i + d < n; d++) {
            if (a[i - d] < a[i - d + 1] && a[i + d] < a[i + d - 1]) {
                max_dist = d;
                continue;
            }
            break;
        }
        /* printf("max_dist = %d, longest_monotonic = %d\n", max_dist, longest_monotonic); */
        if (max_dist == longest_monotonic && peaks.count(i) != 0 && max_dist % 2 == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    /* int n = 10; */
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    set<int> seen;
    for (int i = 0; i < n; i++) {
        /* int x = rand() % 25; */
        /* while (seen.count(x) != 0) { */
        /*     x = rand() % 25; */
        /* } */
        /* a[i] = x; */
        scanf("%d", &a[i]);
    }
    printf("%d\n", bf(n, a));
}
