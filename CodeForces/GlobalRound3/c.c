#include <stdio.h>

int n;
int a[300010];
int o[15000050][2];
int counter;

void swap(int i, int j) {
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
    o[counter][0] = i;
    o[counter][1] = j;
    counter += 1;
}

void swap_with_condition(int i, int j) {
    if (i > j) {
        int tmp = i;
        i = j;
        j = tmp;
    }
    if (j - i >= n / 2) {
        return swap(i, j);
    }
    if (n - j >= n / 2) {
        swap(j, n);
        swap(i, n);
        return swap(j, n);
    }
    if (i - 1 >= n / 2) {
        swap(i, 1);
        swap(j, 1);
        return swap(i, 1);
    }
    swap(i, n);
    swap(1, n);
    swap(1, j);
    swap(1, n);
    return swap(i, n);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        while (i != a[i]) {
            swap_with_condition(i, a[i]);
        }
    }
    printf("%d\n", counter);
    for (int i = 0; i < counter; i++) {
        printf("%d %d\n", o[i][0], o[i][1]);
    }
    return 0;
}
