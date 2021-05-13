#include<bits/stdc++.h>

using namespace std;

void change(char &x) {
    if (x == '1') {
        x = '0';
    } else {
        x = '1';
    }
}



int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        int n;
        scanf("%d", &n);
        string a, b;
        cin >> a >> b;
        vector<int> out;
        char val = a[n - 1];
        for (int i = 0; i < n - 1; i++) {
            if (a[i] != a[i + 1]) {
                out.push_back(i + 1);
                if (a[i] == '1') {
                    val = '0';
                } else {
                    val = '1';
                }
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (b[i] != val) {
                out.push_back(i + 1);
                change(val);
            }
        }
        int s = out.size();
        printf("%d ", s);
        for (int i = 0; i < s; i++) {
            printf("%d ", out[i]);
        }
        printf("\n");
    }
}
