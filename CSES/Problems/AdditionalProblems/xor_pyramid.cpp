#include <bits/stdc++.h>

using namespace std;

int get_contrib_of_2(int x) {
    int answer = 0;
    while (x % 2 == 0) {
        x /= 2;
        answer++;
    }
    return answer;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    vector<int> contrib_of_2(n);
    for (int i = 1; i < n; i++) {
        contrib_of_2[i] = contrib_of_2[i - 1] + get_contrib_of_2(i);
    }
    int answer = 0;
    for (int i = 0; i < n; i++) {
        if (contrib_of_2[n - 1] - contrib_of_2[n - 1 - i] - contrib_of_2[i] == 0) {
            answer ^= a[i];
        }
    }
    printf("%d\n", answer);
}
