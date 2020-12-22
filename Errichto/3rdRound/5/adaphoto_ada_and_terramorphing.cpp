// https://www.spoj.com/problems/ADAPHOTO/

#include <bits/stdc++.h>

#define deb(x) cerr << #x << " = " << x << endl;
#define deb_v(x) cerr << #x << " = ["; \
    for(auto item: x) cerr << item << ", "; \
    cerr << "]\n";
#define deb_a(a, n) cerr << #a << " = [";\
    for (int i = 0; i < n; i++) cerr << a[i] << ", "; \
    cerr << "]\n";

using namespace std;

const int N = 1e6 + 1;

int pref_a[N];
int pref_b[N];
int pre_power[N];
int P = 1e9 + 7;
int B = 5;

int mul(int a, int b) {
    return (long long)a * b % P;
}

int power(int a, int b) {
    int result = 1;
    while (b > 0) {
        if (b % 2 == 1) result = (long long)a * result % P;
        a = (long long)a * a % P;
        b /= 2;
    }
    return result;
}

int divide(int a, int b) {
    return mul(a, power(b, P - 2));
}

int sum(int a, int b) {
    return ((long long)a + b) % P;
}

int sub(int a, int b) {
    int answer = (a - b) % P;
    if (answer < 0) answer += P;
    return answer;
}

int hash_for_char(char ch) {
    string templ = "^v-~";
    for(int i = 0; i < (int) templ.length(); i++) {
        if(templ[i] == ch) {
            return i;
        }
    }
    assert(false);
}
                                                                  //  2^30=1e9
int main() { // O(log(n) * (n * log(P) + n * log(n))) => O(nlogn * (log(P) + log(n)))
    string a, b;
    cin >> a;
    cin >> b;
    const int n = a.size();
    const int m = b.size();
    /*int hash_for_char[4];
    for (int i = 0; i < 4; i++) {
        hash_for_char[i] = rand();
    }*/
    pre_power[0] = 1;
    for (int i = 1; i < N; i++) {
        pre_power[i] = mul(pre_power[i - 1], B);
    }
	deb(pre_power);
    for (int i = 0; i < n; i++) {
        pref_a[i + 1] = sum(pref_a[i], mul(hash_for_char(a[i]), pre_power[i]));
        pref_b[i + 1] = sum(pref_b[i], mul(hash_for_char(b[i]), pre_power[i]));
    }
    int left = 0, right = min(n, m); // O(n)
    while (left < right) { // O(log(n))
        int mid = left + (right - left) / 2;
        vector<int> hashes_a;
        vector<int> hashes_b;
        for (int i = mid; i < n + 1; i++) { // O(n)
            hashes_a.push_back(divide(sub(pref_a[i], pref_a[i - mid]), i - mid + 1)); // log(P)
        }
        for (int i = mid; i < m + 1; i++) {
            hashes_b.push_back(divide(sub(pref_b[i], pref_b[i - mid]), i - mid + 1));
        }
        sort(hashes_a.begin(), hashes_a.end()); // O(nlogn)
        sort(hashes_b.begin(), hashes_b.end());
        int i_a = 0, i_b = 0;
        bool found = false;
        while (i_a < n && i_b < m) { // O(n)
            if (hashes_a[i_a] < hashes_b[i_b]) {
                i_a++;
            } else if (hashes_a[i_a] > hashes_b[i_b]) {
                i_b++;
            } else {
                printf("size = %d\n", mid);
                printf("hashes_a = [");
                for (int i = 0; i < (int)hashes_a.size(); i++) {
                    printf("%d ", hashes_a[i]);
                }
                printf("]\n");
                printf("hashes_b = [");
                for (int i = 0; i < (int)hashes_b.size(); i++) {
                    printf("%d ", hashes_b[i]);
                }
                printf("]\n");
                printf("our match is on i_a = %d, i_b = %d; %d == %d\n", i_a, i_b, hashes_a[i_a], hashes_b[i_b]);
                found = true;
                break;
            }
        }
        if (found) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    printf("pref_a = [");
    for (int i = 0; i < n + 1; i++) {
        printf("%d ", pref_a[i]);
    }
    printf("]\n");
    printf("pref_b = [");
    for (int i = 0; i < m + 1; i++) {
        printf("%d ", pref_a[i]);
    }
    printf("]\n");
    int x = 1;
    printf("Every %d of a = [", x);
    for (int i = x; i < n + 1; i++) {
        printf("%d ", sub(pref_a[i], pref_a[i - x]));
    }
    printf("]\n");
    printf("Every %d of b = [", x);
    for (int i = x; i < m + 1; i++) {
        printf("%d ", sub(pref_b[i], pref_b[i - x]));
    }
    printf("]\n");
    printf("%d\n", right);
}
