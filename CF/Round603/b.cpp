#include <bits/stdc++.h>

using namespace std;

string change_pin(string pin, set<string> &so_far) {
    string initial_pin;
    for (int i = 0; i < 4; i++) {
        for (char x : {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}) {
            if (pin[i] == x) {
                continue;
            }
            pin[i] = x;
            if (so_far.count(pin) < 1) {
                return pin;
            }
        }
        pin = initial_pin;
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        int n;
        scanf("%d", &n);
        vector<string> pins(n);
        set<string> so_far;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            so_far.insert(s);
            pins[i] = s;
        }
        int output = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (pins[i] == pins[j]) {
                    pins[j] = change_pin(pins[j], so_far);
                    so_far.insert(pins[j]);
                    output++;
                }
            }
        }
        printf("%d\n", output);
        for (string pin : pins) {
            cout << pin << "\n";
        }
    }
}
