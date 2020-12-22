#include <bits/stdc++.h>

using namespace std;

vector<int> merge_sort(vector<int> a) {
    int n = a.size();
    if (n == 1 || n == 0) {
        return a;
    }
    int half = int((n + 1) / 2);
    vector<int> first = merge_sort(vector<int>(a.begin(), a.begin() + half));
    vector<int> second = merge_sort(vector<int>(a.begin() + half, a.end()));
    vector<int> out(n);
    int i = 0, j = 0, index = 0;
    for (int index = 0; index < n; index++) {
        if (i >= first.size()) {
            out[index] = second[j];
            j++;
            continue;
        }
        if (j >= second.size()) {
            out[index] = first[i];
            i++;
            continue;
        }
        if (first[i] < second[j]) {
            out[index] = first[i];
            i++;
        } else {
            out[index] = second[j];
            j++;
        }
    }
    return out;
}

int main() {
    vector<int> x = {5, 4, 1, 8, 7, 2, 6, 3, 0, 1, 1, 1};
    int n = x.size();
    x = merge_sort(x);
    for (int i = 0; i < n; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");
}
