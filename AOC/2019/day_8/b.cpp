#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream input("input.txt");

    if (input.is_open()) {
        int x = 25, y = 6;
        int m = x * y;
        string s;
        getline(input, s);
        int n = s.size();
        vector<char> out(m);
        for (int i = 0; i < m; i++) {
            int pixel = i;
            while (pixel < n) {
                if (s[pixel] == '0') {
                    break;
                } else if (s[pixel] == '1') {
                    break;
                } else {
                    pixel += m;
                }
            }
            if (pixel > n) {
                out[i] = '2';
            } else {
                out[i] = s[pixel];
            }
        }
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++) {
                if (out[i * x + j] == '0') {
                    printf(" ");
                } else {
                    printf("#");
                }
                /* printf("%c", out[i * x + j]); */
            }
            printf("\n");
        }
        printf("\n");
        return 0;
    }
    printf("Unable to open 'input.txt'\n");
}
