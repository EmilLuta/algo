#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<string> out(17);
    out[1] = "1";
    for (int i = 2; i <= 16; i++) {
        out[i] = out[i - 1] + " " + to_string(i) + " " + out[i - 1];
    }
    cout << out[n] << endl;
}
