#include <bits/stdc++.h>

using namespace std;

int bs(const vector<int>& a, int x) {
    int start = 0;
    int n = a.size();
    int end = n - 1;
    int answer = n;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (a[mid] < x) {
            start = mid + 1;
        } else {
            answer = mid;
            end = mid - 1;
        }
    }
    return answer;
}

int main() {
    int n, s;
    scanf("%d%d", &n, &s);
    vector<int> a(n);
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        m[a[i]]++;
    }
    sort(a.begin(), a.end());
    int answer = 0;
    for (int i = 0; i < n; i++) {
        int left = bs(a, a[i]);
        int right = bs(a, a[i] + s);
        if (a[right] == a[i] + s) {
            right += m[a[right]] - 1;
        } else {
            right--;
        }
        answer = max(answer, right - left + 1);
    }
    printf("%d\n", answer);
}

// VERSION A

/* int bs_left(const vector<int>& a, int x) { */
/*     int start = 0; */
/*     int end = (int)a.size() - 1; */
/*     int answer = -1; */
/*     while (start <= end) { */
/*         int mid = start + (end - start) / 2; */
/*         if (a[mid] < x) { */
/*             start = mid + 1; */
/*         } else { */
/*             if (a[mid] == x) { */
/*                 answer = mid; */
/*             } */
/*             end = mid - 1; */
/*         } */
/*     } */
/*     return answer; */
/* } */

/* int bs_right(const vector<int>& a, int x) { */
/*     int start = 0; */
/*     int end = (int)a.size() - 1; */
/*     int answer = -1; */
/*     while (start <= end) { */
/*         int mid = start + (end - start) / 2; */
/*         if (a[mid] > x) { */
/*             end = mid - 1; */
/*         } else { */
/*             answer = mid; */
/*             start = mid + 1; */
/*         } */
/*     } */
/*     return answer; */
/* } */

/* int main() { */
/*     int n, s; */
/*     scanf("%d%d", &n, &s); */
/*     vector<int> a(n); */
/*     for (int i = 0; i < n; i++) { */
/*         scanf("%d", &a[i]); */
/*     } */
/*     sort(a.begin(), a.end()); */
/*     int answer = 0; */
/*     for (int i = 0; i < n; i++) { */
/*         int left = bs_left(a, a[i]); */
/*         int right = bs_right(a, a[i] + s); */
/*         answer = max(answer, right - left + 1); */
/*     } */
/*     printf("%d\n", answer); */
/* } */


// VERSION B

/* int bs_left(const vector<int>& a, int x) { */
/*     int start = 0; */
/*     int end = (int)a.size() - 1; */
/*     int answer = -1; */
/*     while (start <= end) { */
/*         int mid = start + (end - start) / 2; */
/*         if (a[mid] < x) { */
/*             start = mid + 1; */
/*         } else { */
/*             answer = mid; */
/*             end = mid - 1; */
/*         } */
/*     } */
/*     return answer; */
/* } */

/* int bs_right(const vector<int>& a, int x) { */
/*     int start = 0; */
/*     int end = (int)a.size() - 1; */
/*     int answer = -1; */
/*     while (start <= end) { */
/*         int mid = start + (end - start) / 2; */
/*         if (a[mid] > x) { */
/*             end = mid - 1; */
/*         } else { */
/*             answer = mid; */
/*             start = mid + 1; */
/*         } */
/*     } */
/*     return answer; */
/* } */

/* int main() { */
/*     int n, s; */
/*     scanf("%d%d", &n, &s); */
/*     vector<int> a(n); */
/*     for (int i = 0; i < n; i++) { */
/*         scanf("%d", &a[i]); */
/*     } */
/*     sort(a.begin(), a.end()); */
/*     int answer = 0; */
/*     for (int i = 0; i < n; i++) { */
/*         int left = bs_left(a, a[i]); */
/*         int right = bs_right(a, a[i] + s); */
/*         answer = max(answer, right - left + 1); */
/*     } */
/*     printf("%d\n", answer); */
/* } */
