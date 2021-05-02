#include <bits/stdc++.h>

using namespace std;

int f(vector<int> a) {
    int n = a.size();
    vector<int> lengths;
    for(int i = 0; i < n - 1; i++) {
        bool inc = (a[i] < a[i+1]);
        int len = 2;
        while(i + 2 < n && inc == (a[i+1] < a[i+2])) {
            i++;
            len++;
        }
        lengths.push_back(len);
    }
    int me = -1;
    for(int i = (a[0] > a[1]); i < (int) lengths.size() - 1; i += 2) {
        if(lengths[i] == lengths[i+1]) {
            me = max(me, lengths[i]);
        }
    }
    if(me == -1 || me % 2 == 0) {
        return 0;
    }
    // check if only those two values are equal to "me" and nothing is bigger
    int count_equal = 0;
    for(int x : lengths) {
        if(x > me) {
            return 0;
        }
        if(x == me) {
            count_equal++;
        }
    }
    return count_equal == 2;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("%d\n", f(a));
}
