#include <bits/stdc++.h>

using namespace std;

int pick_pivot_index(vector<int>& a, int start, int end) {
    return start;
}

int partition(vector<int>& a, int start, int end) {
    int p_i = pick_pivot_index(a, start, end);
    swap(a[p_i], a[start]);
    printf("using pivot %d\n", a[start]);
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

void quicksort(vector<int>& a, int start, int end) {
    if (start >= end) {
        return;
    }
    int index = partition(a, start, end);
    printf("After partioning from %d to %d with pivot %d, we got:\n[", start, end, a[index]);
    for (int i = start; i <= end; i++) {
        printf("%d ", a[i]);
    }
    printf("]\n");
    quicksort(a, start, index - 1);
    quicksort(a, index + 1, end);
}

int main() {
    int n = 8;
    vector<int> a = {3, 8, 2, 5, 1, 4, 7, 6};
    quicksort(a, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
