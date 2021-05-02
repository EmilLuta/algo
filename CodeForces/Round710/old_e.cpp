#include <bits/stdc++.h>

using namespace std;

// ios::sync_with_stdio(0);
// cin.tie(0);

# define deb_v(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << item << " "; \
    cerr << ")\n";

# define deb(x) cerr << #x << " = " << x << "\n";

# define deb_v_p(x) cerr << #x << " = ("; \
    for (auto item: x) cerr << "(" << item.first << ", " << item.second << ") "; \
    cerr << ")\n";

void get_smallest(int n, vector<int>& a) {
    set<int> seen;
    vector<int> answer(n, -1);
    int free_pos = 0;
    int smallest_unused = 1;
    for (int i = 1; i < n; i++) {
        while(a[i] == a[i - 1]) {
            i++;
        }
        answer[free_pos] = a[i - 1];
        free_pos++;
        seen.insert(a[i - 1]);
        for (int x = free_pos; x < i; x++) {
            answer[x] = smallest_unused;
            seen.insert(smallest_unused);
            while (seen.count(smallest_unused) != 0) {
                smallest_unused++;
            }
        }
        free_pos = i;
    }
    answer[free_pos] = a[n - 1];
    seen.insert(a[n - 1]);
    free_pos++;
    for (int x = free_pos; x < n; x++) {
        answer[x] = smallest_unused;
        seen.insert(smallest_unused);
        while (seen.count(smallest_unused) != 0) {
            smallest_unused++;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", answer[i]);
    }
    printf("\n");
    printf("ba esti prost?\n");
}

void get_biggest(int n, vector<int>& a) {
    printf("ce plm???\n");
    set<int> seen;
    vector<int> answer(n, -1);
    int free_pos = 0;
    int biggest_unused = 1;
    printf("aici?\n");
    for (int i = 1; i < n; i++) {
        printf("wtf?\n");
        while(a[i] == a[i - 1]) {
            i++;
        }
        answer[free_pos] = a[i - 1];
        free_pos++;
        seen.insert(a[i - 1]);
        biggest_unused = a[i - 1];
        for (int x = free_pos; x < i; x++) {
            while (seen.count(biggest_unused) != 0) {
                biggest_unused--;
            }
            answer[x] = biggest_unused;
            seen.insert(biggest_unused);
        }
        free_pos = i;
        printf("trouble?\n");
    }
    printf("before?\n");
    answer[free_pos] = a[n - 1];
    seen.insert(a[n - 1]);
    free_pos++;
    for (int x = free_pos; x < n; x++) {
        while (seen.count(biggest_unused) != 0) {
            biggest_unused--;
        }
        answer[x] = biggest_unused;
        seen.insert(biggest_unused);
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", answer[i]);
    }
    printf("\n");
    printf("ola?\n");
    return;
}

void solve(int t) {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    /* get_smallest(n, a); */
    printf("e ok?\n");
    get_biggest(n, a);
    return;
    printf("ce plm\n");
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
