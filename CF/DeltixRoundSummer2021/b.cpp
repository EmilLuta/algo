#include <bits/stdc++.h>

using namespace std;

int even_start(vector<int>& a, int n) {
    int answer = 0;
    vector<int> odd, even;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            if (a[i] % 2 == 0) {
                if ((int)odd.size() != 0) {
                    int x = odd[odd.size() - 1];
                    odd.pop_back();
                    answer += i - x;
                    odd.push_back(i);
                }
            } else {
                if ((int)even.size() != 0) {
                    int x = even[even.size() - 1];
                    even.pop_back();
                    answer += i - x;
                } else {
                    odd.push_back(i);
                }
            }
        } else {
            if (a[i] % 2 == 0) {
                if ((int)odd.size() != 0) {
                    int x = odd[odd.size() - 1];
                    odd.pop_back();
                    answer += i - x;
                } else {
                    even.push_back(i);
                }
            } else {
                if ((int)even.size() != 0) {
                    int x = even[even.size() - 1];
                    even.pop_back();
                    answer += i - x;
                    even.push_back(i);
                }
            }
        }
    }
    return answer;
}

int odd_start(vector<int>& a, int n) {
    int answer = 0;
    vector<int> odd, even;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            if (a[i] % 2 == 1) {
                if ((int)even.size() != 0) {
                    int x = even[even.size() - 1];
                    even.pop_back();
                    answer += i - x;
                    even.push_back(i);
                }
            } else {
                if ((int)odd.size() != 0) {
                    int x = odd[odd.size() - 1];
                    odd.pop_back();
                    answer += i - x;
                } else {
                    even.push_back(i);
                }
            }
        } else {
            if (a[i] % 2 == 1) {
                if ((int)even.size() != 0) {
                    int x = even[even.size() - 1];
                    even.pop_back();
                    answer += i - x;
                } else {
                    odd.push_back(i);
                }
            } else {
                if ((int)odd.size() != 0) {
                    int x = odd[odd.size() - 1];
                    odd.pop_back();
                    answer += i - x;
                    odd.push_back(i);
                }
            }
        }
    }
    return answer;
}

int get_parity(vector<int>& a, int n) {
    int odd = 0, even = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            even++;
        } else {
            odd++;
        }
    }
    if (abs(odd - even) > 1) {
        return -1;
    }
    if (odd > even) {
        return odd_start(a, n);
    }
    if (odd < even) {
        return even_start(a, n);
    }
    return min(odd_start(a, n), even_start(a, n));
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        int n;
        scanf("%d", &n);
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        printf("%d\n", get_parity(a, n));
    }
}
