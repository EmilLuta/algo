#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> a;
    for (int i = 1; i <= k + 1; i++) {
        cout << "? ";
        for (int j = 1; j <= k + 1; j++) {
            if (i != j) {
                cout << j << " ";
            }
        }
		cout << "\n";
        cout.flush();
		int pos, number;
		scanf("%d%d", &pos, &number);
		a.push_back(number);
    }
    int m = INT_MIN;
    for (int i : a) {
        m = max(m, i);
    }
    int answer = 0;
    for (int i : a) {
        if (i == m) {
            answer++;
        }
    }
    printf("! %d\n", answer);
}
