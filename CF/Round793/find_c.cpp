#include <bits/stdc++.h>

using namespace std;

int lis(vector<int>& a) {
    int n = a.size();
    vector<int> l;
    for (int i = 0; i < n ; i++) {
        int index = lower_bound(l.begin(), l.end(), a[i]) - l.begin();
        if (index == (int)l.size()) {
            l.push_back(a[i]);
            continue;
        }
        l[index] = a[i];
    }
    return l.size();
}

int solve(vector<int> a) {
    int n = a.size();
    sort(a.begin(), a.end());
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        m[a[i]] = min(m[a[i]] + 1, 2);
    }
    /* for (pair<int, int> p : m) { */
    /*     printf("%d: %d\n", p.first, p.second); */
    /* } */
    /* printf("\n"); */
    int mid_val = -1;
    for (pair<int, int> p : m) {
        if (p.second == 1) {
            mid_val = p.first;
        }
    }
    if (mid_val == -1) {
        mid_val = a[n - 1];
        /* printf("mid val = %d\n", mid_val); */
    }
    m[mid_val]--;
    if (m[mid_val] == 0) {
        m.erase(mid_val);
    }
    /* for (pair<int, int> p : m) { */
    /*     printf("%d: %d\n", p.first, p.second); */
    /* } */
    /* printf("\n"); */
    int bw = 1;
    int fw = 1;
    for (pair<int, int> p : m) {
        int got = p.second;
        if (bw < fw) {
            bw++;
            if (got == 2) {
                fw++;
            }
        } else {
            fw++;
            if (got == 2) {
                bw++;
            }
        }
        /* printf("after we put %d of %ds, we got fw = %d, bw = %d\n", p.second, p.first, fw, bw); */
    }
    return min(bw, fw);
    /* vector<int> out(n, 0); */
    /* int index = 0; */
    /* int left = 0; */
    /* int right = n - 1; */
    /* while (index < n) { */
    /*     out[left] = a[index]; */
    /*     left++; */
    /*     index++; */
    /*     if (index < n) { */
    /*         out[right] = a[index]; */
    /*         index++; */
    /*         right--; */
    /*     } */
    /* } */
    /* int fw = lis(out); */
    /* reverse(out.begin(), out.end()); */
    /* int bw = lis(out); */
    /* return min(fw, bw); */
}

int bf(vector<int> a) {
    sort(a.begin(), a.end());
    int answer = 0;
    do {
        int fw = lis(a);
        vector<int> b(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int bw = lis(b);
        answer = max(answer, min(fw, bw));
    } while (next_permutation(a.begin(), a.end()));
    return answer;
}

int main() {
    int times = 0;
    while (true) {
        int n = 7;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = rand() % 10 + 1;
        }
        int x = bf(a);
        int z = solve(a);
        if (x != z) {
            printf("bf = %d, mine = %d\n", x, z);
            for (int i = 0; i < n; i++) {
                printf("%d ", a[i]);
            }
            printf("\n");
            return 0;
        }
        times++;
        /* printf("%d runs\n", times); */
        if (times % 100 == 0) {
            printf("%d runs\n", times);
        }
    }
}
