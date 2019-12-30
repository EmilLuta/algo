#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

int main() {
    int start = 264793;
    int end = 803935;
    int output = 0;
    vector<vector<int>> all;
    for (int i = start; i <= end; i++) {
        int current = i;
        vector<int> number;
        while (current > 0) {
            int c = current % 10;
            current = current / 10;
            number.push_back(c);
        }
        int ok = true;
        vector<int> counter(10, 0);
        counter[number[0]]++;
        for (int j = 1; j < 6; j++) {
            if (number[j] > number[j - 1]) {
                ok = false;
                break;
            }
            counter[number[j]]++;
        }
        if (ok) {
            for (int j = 0; j <= 9; j++) {
                if (counter[j] == 2) {
                    all.push_back(number);
                    output++;
                    break;
                }
            }
        }
    }
    printf("%d\n", output);
    for (vector<int> x : all) {
        for (int i = 5; i >= 0; i--) {
            printf("%d ", x[i]);
        }
        printf("\n");
        usleep(10000);
    }
}
