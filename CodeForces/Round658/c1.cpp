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
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] != b[i]) {
                if (i == 0) {
                    if (a[0] != b[0]) {
                        out.push_back(1);
                    }
                } else {
                    if (a[0] == b[i]) {
                        out.push_back(1);
                        change(a[0]);
                    }
                    out.push_back(i + 1);
                    int mid = i / 2;
                    for (int j = 0; j <= mid; j++) {
                        change(a[j]);
                        change(a[i - j]);
                        swap(a[j], a[i - j]);
                    }
                    if (i % 2 == 0) {
                        change(a[mid]);
                    }
                }
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
