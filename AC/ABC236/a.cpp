#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int a, b;
    scanf("%d%d", &a, &b);
    a--;
    b--;
    swap(s[a], s[b]);
    cout << s << endl;
}
