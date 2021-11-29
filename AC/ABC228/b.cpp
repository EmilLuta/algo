#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, start;
    scanf("%d%d", &n, &start);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    vector<bool> seen(n, false);
    int curr = start - 1;
    int answer = 0;
    while (!seen[curr]) {
        seen[curr] = true;
        answer++;
        curr = a[curr] - 1;
    }
    printf("%d\n", answer);
}
