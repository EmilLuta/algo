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

int get_smallest_unseen(int starting_from, set<int>& seen) {
    while (seen.count(starting_from) != 0) {
        starting_from++;
    }
    seen.insert(starting_from);
    return starting_from;
}

void print_smallest(int n, vector<int> answer) {
    set<int> seen;
    int smallest_unseen = 1;
    for (int i = 0; i < n; i++) {
        if (answer[i] == -1) {
            smallest_unseen = get_smallest_unseen(smallest_unseen, seen);
            answer[i] = smallest_unseen;
        } else {
            seen.insert(answer[i]);
        }
        printf("%d ", answer[i]);
    }
    printf("\n");
}

void print_biggest(int n, vector<int> answer) {
    set<int> to_be_used;
    for (int i = 1; i <= n; i++) {
        to_be_used.insert(i);
    }
    for (int i = 0; i <= n; i++) {
        to_be_used.erase(answer[i]);
    }
    int biggest_so_far;
    for (int i = 0; i < n; i++) {
        if (answer[i] != -1) {
            biggest_so_far = answer[i];
        } else {
            set<int>::const_iterator it = to_be_used.lower_bound(biggest_so_far);
            it--;
            answer[i] = *it;
            to_be_used.erase(it);
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", answer[i]);
    }
    printf("\n");
}

void solve(int t) {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int change_pos = 0;
    vector<int> answer(n, -1);
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) {
            answer[change_pos] = a[i - 1];
            change_pos = i;
        }
    }
    answer[change_pos] = a[n - 1];
    print_smallest(n, vector<int>(answer.begin(), answer.end()));
    print_biggest(n, vector<int>(answer.begin(), answer.end()));
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
