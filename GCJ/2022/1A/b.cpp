#include <bits/stdc++.h>

using namespace std;

const long long MAX = 1e9;


void solve(int t) {
    /* cerr << "Running test case #" << t << endl; */
    int n;
    scanf("%d", &n);
    /* cin >> n; */
    /* cerr << "Received n = " << n << endl; */
    long long sum = 0;
    vector<int> vals;
    int pow = 1;
    int n_first = 30;
    for (int i = 0; i < n_first; i++) {
        vals.push_back(pow);
        printf("%d ", pow);
        /* cout << pow << " "; */
        /* cerr << "showing " << pow << endl; */
        sum += pow;
        pow *= 2;
    }
    /* cerr << "Showed first " << n_first << " numbers\n"; */
    for (int i = 1e9; i > 1e9 - (n - n_first); i--) {
        vals.push_back(i);
        printf("%d ", i);
        /* cerr << "then showing " << i << endl; */
        /* cout << i << " "; */
        sum += i;
    }
    /* cerr << "Showed next " << n - n_first << " numbers\n"; */
    /* printf("\n"); */
    fflush(stdout);
    cout << endl;
    /* cerr << "new line\n"; */
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        /* cin >> x; */
        /* cerr << "read the " << i << "th number\n"; */
        vals.push_back(x);
        sum += x;
    }
    sum /= 2;
    int i = n * 2 - 1;
    while (sum != 0) {
        if (sum >= vals[i]) {
            sum -= vals[i];
            printf("%d ", vals[i]);
            /* cout << vals[i] << " "; */
        }
        i--;
    }
    printf("\n");
    fflush(stdout);
    /* cout << endl; */
}

int main() {
    /* cerr << "started\n"; */
    int t;
    scanf("%d", &t);
    /* cerr << "received t = " << t << "\n"; */
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
