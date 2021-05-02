#include <bits/stdc++.h>

using namespace std;

bool increment_string(string& a) {
    int n = a.length();
    int i = n - 1;
    while (i >= 0 && a[i] == 'z') {
        a[i] = 'a';
        i--;
    }
    if (i == -1) {
        return false;
    }
    a[i] += 1;
    return true;
}

bool has_letter(string a, char k) {
    for (char x : a) {
        if (k == x) {
            return true;
        }
    }
    return false;
}

int main() {
    string a, b;
    char k;
    cin >> a >> b;
    cin >> k;
    while (increment_string(a) && a < b) {
        if (has_letter(a, k)) {
            cout << a << endl;
            return 0;
        }
    }
    printf("-1\n");
}
