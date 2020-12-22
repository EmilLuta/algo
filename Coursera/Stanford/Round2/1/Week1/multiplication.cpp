#include <bits/stdc++.h>
/* #include <unistd.h> */

using namespace std;

/* string multiplication(string a, string b) { */
/*     int A = a.size(); */
/*     int B = b.size(); */
/*     reverse(a.begin(), a.end()); */
/*     reverse(b.begin(), b.end()); */
/*     vector<vector<int>> mult(B); */
/*     int n = A + B; */
/*     for (int i = 0; i < B; i++) { */
/*         mult[i].resize(n); */
/*         int carry = 0; */
/*         for (int j = 0; j < A; j++) { */
/*             int multiplication = (a[j] - '0') * (b[i] - '0') + carry; */
/*             mult[i][j + i] = (multiplication % 10); */
/*             carry = multiplication / 10; */
/*         } */
/*         if (carry != 0) { */
/*             mult[i][A + i] = carry; */
/*         } */
/*     } */
/*     string result = ""; */
/*     int carry = 0; */
/*     for (int i = 0; i < n; i++) { */
/*         int current = carry; */
/*         for (int j = 0; j < B; j++) { */
/*             current += mult[j][i]; */
/*         } */
/*         result += (current % 10) + '0'; */
/*         carry = current / 10; */
/*     } */
/*     while (result[result.size() - 1] == '0') { */
/*         result.pop_back(); */
/*     } */
/*     reverse(result.begin(), result.end()); */
/*     return result; */
/* } */

vector<int> pad_to_size(vector<int> a, int n) {
    vector<int> out;
    for (int i = 0; i < n - a.size(); i++) {
        out.push_back(0);
    }
    for (int i = 0; i < a.size(); i++) {
        out.push_back(a[i]);
    }
    return out;
}

vector<int> mul(vector<int> a, vector<int> b) {
    if (a.size() == 0) {
        return a;
    }
    int m = a[0] * b[0];
    vector<int> out;
    if (m == 0) {
        out.push_back(0);
        return out;
    }
    while (m != 0) {
        out.push_back(m % 10);
        m /= 10;
    }
    reverse(out.begin(), out.end());
    return out;
}

vector<int> add(vector<int> a, vector<int> b) {
    int carry = 0;
    int n = max(a.size(), b.size());
    a = pad_to_size(a, n);
    b = pad_to_size(b, n);
    vector<int> out;
    for (int i = n - 1; i >= 0; i--) {
        int s = a[i] + b[i] + carry;
        out.push_back(s % 10);
        carry = s / 10;
    }
    if (carry != 0) {
        out.push_back(carry);
    }
    while (out[out.size() - 1] == 0) {
        out.pop_back();
    }
    reverse(out.begin(), out.end());
    return out;
}

vector<int> diff(vector<int> a, vector<int> b) {
    int n = a.size();
    b = pad_to_size(b, n);
    vector<int> out;
    for (int i = 0; i < n; i++) {
        int d = a[i] - b[i];
        if (d < 0) {
            d += 10;
            int index = i - 1;
            while (out[index] == 0) {
                index--;
            }
            out[index]--;
            index++;
            while (index < i) {
                out[index] = 9;
                index++;
            }
        }
        out.push_back(d);
    }
    reverse(out.begin(), out.end());
    while (out[out.size() - 1] == 0) {
        out.pop_back();
    }
    reverse(out.begin(), out.end());
    return out;
}

vector<int> kara(vector<int> x, vector<int> y) {
    int n = max(x.size(), y.size());
    x = pad_to_size(x, n);
    y = pad_to_size(y, n);
    if (n <= 1) {
        return mul(x, y);
    }
    int left = n / 2;
    int right = n - left;
    vector<int> a, b, c, d;
    for (int i = 0; i < left; i++) {
        a.push_back(x[i]);
        c.push_back(y[i]);
    }
    for (int i = left; i < n; i++) {
        b.push_back(x[i]);
        d.push_back(y[i]);
    }
    vector<int> p1 = kara(a, c);
    vector<int> p2 = kara(b, d);
    vector<int> p3 = kara(add(a, b), add(c, d));
    vector<int> p4 = diff(p3, add(p1, p2));
    for(int i = 0; i < 2 * right; i++) {
        p1.push_back(0);
    }
    for (int i = 0; i < right; i++) {
        p4.push_back(0);
    }
    return add(p1, add(p2, p4));
}

int main() {
    string a = "3141592653589793238462643383279502884197169399375105820974944592";
    string b = "2718281828459045235360287471352662497757247093699959574966967627";
    /* a = "70"; */
    /* b = "135"; */
    /* a = "456"; */
    /* b = "12"; */
    /* a = "5678"; */
    /* b = "1234"; */
    /* a = "134"; */
    /* b = "46"; */
    /* a = "1"; */
    /* b = "0"; */
    /* a = "34"; */
    /* b = "46"; */
    a = "12341234";
    b = "1234123";
    vector<int> x;
    vector<int> y;
    for (int i = 0; i < a.length(); i++) {
        x.push_back(a[i] - '0');
    }
    for (int i = 0; i < b.length(); i++) {
        y.push_back(b[i] - '0');
    }
    /* assert(regular == karatsuba); */
    vector<int> answer = kara(x, y);
    for (int i = 0; i < answer.size(); i++) {
        printf("%d", answer[i]);
    }
    printf("\n");
}
