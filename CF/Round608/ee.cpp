#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    map<int, int> counter;
    for (int i = n; i > 0; i--) {
        int x = i;
        int c = 1;
        if (counter.count(x) != 0) {
            continue;
        }
        if (x == 2) {
            printf("Adding %d of twos from %d\n", c, i);
        }
        counter[x] += c;
        if (x % 2 == 1) {
            c++;
            x--;
        }
        if (x == 2) {
            printf("Adding %d of twos from %d\n", c, i);
        }
        counter[x] += c;
        while (x > 0) {
            x /= 2;
            if (counter.count(x) == 0) {
                c++;
            }
            if (x == 2) {
                printf("Adding %d of twos from %d\n", c, i);
            }
            counter[x] += c;
            if (x % 2 == 1) {
                x--;
                if (counter.count(x) == 0) {
                    c++;
                }
                if (x == 2) {
                    printf("Adding %d of twos from %d\n", c, i);
                }
                counter[x] += c;
            }
        }
    }
    /* for (int i = 1; i <= n; i++) { */
    /*     int x = i; */
    /*     vector<int> out; */
    /*     counter[x]++; */
    /*     out.push_back(x); */
    /*     while (x != 0) { */
    /*         if (x % 2 == 1) { */
    /*             x--; */
    /*         } else { */
    /*             x /= 2; */
    /*         } */
    /*         counter[x]++; */
    /*         out.push_back(x); */
    /*     } */
    /*     /1* printf("For i = %d we got:\n", i); *1/ */
    /*     /1* for (int w : out) { *1/ */
    /*     /1*     printf("%d ", w); *1/ */
    /*     /1* } *1/ */
    /*     /1* printf("\n"); *1/ */
    /* } */
    int correct = 1;
    for (pair<int, int> p : counter) {
        printf("%d => %d\n", p.first, p.second);
        if (p.second >= k) {
            correct = p.first;
        }
    }
    printf("%d\n", correct);
}
