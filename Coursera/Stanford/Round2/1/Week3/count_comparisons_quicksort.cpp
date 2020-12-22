#include <bits/stdc++.h>

using namespace std;

int pick_pivot_index_first(vector<int>& a, int start, int end) {
    return start;
}

int pick_pivot_index_end(vector<int>& a, int start, int end) {
    return end;
}

int pick_pivot_index_median(vector<int>& a, int start, int end) {
    int mid = (end + start) / 2;
    if ((a[start] < a[mid] && a[mid] < a[end]) || (a[end] < a[mid] && a[mid] < a[start])) {
        return mid;
    }
    if ((a[mid] < a[start] && a[start] < a[end]) || (a[end] < a[start] && a[start] < a[mid])) {
        return start;
    }
    return end;
}

int partition(vector<int>& a, int start, int end) {
    int p_i = pick_pivot_index_median(a, start, end);
    swap(a[p_i], a[start]);
    /* printf("using pivot %d\n", a[start]); */
    int i = start + 1;
    for (int j = start + 1; j <= end; j++) {
        if (a[start] > a[j]) {
            if (i != j) {
                swap(a[i], a[j]);
            }
            i++;
        }
    }
    swap(a[i - 1], a[start]);
    return i - 1;
}

void quicksort(vector<int>& a, int start, int end, long long& inversions) {
    if (start >= end) {
        return;
    }
    inversions += end - start;
    int index = partition(a, start, end);
    /* printf("After partioning from %d to %d with pivot %d, we got:\n[", start, end, a[index]); */
    /* for (int i = start; i <= end; i++) { */
    /*     printf("%d ", a[i]); */
    /* } */
    /* printf("]\n"); */
    quicksort(a, start, index - 1, inversions);
    quicksort(a, index + 1, end, inversions);
}

int main() {
    freopen("in.txt", "r", stdin);
    int n = 10000;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    long long inversions = 0;
    quicksort(a, 0, n - 1, inversions);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    printf("inversions = %lld\n", inversions);
}
