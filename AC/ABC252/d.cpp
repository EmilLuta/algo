#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    map<int, long long> occ;
    long long all = 0;
    long long answer = 0;
    long long to_remove = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        /* to_remove -= occ[a[i]] * (occ[a[i]] - 1) / 2; */
        occ[a[i]]++;
        /* to_remove += occ[a[i]] * (occ[a[i]] - 1) / 2; */
        all++;
        long long left = all - occ[a[i]];
        /* printf("all = %lld, left = %lld\n", all, left); */
        answer += left * (left - 1) / 2 - to_remove + (occ[a[i]] - 1) * (occ[a[i]] - 2) / 2;
        /* printf("adding %lld when at value %d at a total of %lld with to_remove = %lld\n", left * (left - 1) / 2 - to_remove, a[i], answer, to_remove); */
        to_remove -= (occ[a[i]] - 1) * (occ[a[i]] - 2) / 2;
        to_remove += occ[a[i]] * (occ[a[i]] - 1) / 2;
        /* printf("to_remove lost %lld and added %lld, now at %lld\n", occ[a[i] - 1] * (occ[a[i] - 1] - 1) / 2, occ[a[i]] * (occ[a[i]] - 1) / 2, to_remove); */
    }
    printf("%lld\n", answer);
}
