#include <bits/stdc++.h>

using namespace std;

string to_binary(long long k) {
    string no = "";
    while (k > 0) {
        no.push_back((k % 2) == 0 ? '0' : '2');
        k /= 2;
    }
    reverse(no.begin(), no.end());
    return no;
}

int main() {
    long long k;
    scanf("%lld", &k);
    string s = to_binary(k);
    cout << s << "\n";
}
