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

bool good(vector<int>& a, vector<int>& b) {
    for (int i = 0; i < 26; i++) {
        if (b[i] > a[i]) {
            return false;
        }
    }
    return true;
}

int search_min(vector<vector<int>>& values, vector<int>& target) {
    int start = 0;
    int end = (int)values.size() - 1;
    int answer = -1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (good(values[mid], target)) {
            answer = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return answer;
}

int search_max(vector<vector<int>>& values, vector<int>& target) {
    int start = 0;
    int end = (int)values.size() - 1;
    int answer = -1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (good(values[mid], target)) {
            answer = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return answer;
}

int search(vector<int>& prev_values_in_b, vector<int>& values_in_b, vector<vector<int>>& values_after_index) {
    int minimum = search_min(values_after_index, prev_values_in_b);
    int maximum = search_max(values_after_index, values_in_b);
    if (maximum == -1 || minimum == -1) {
        return 0;
    }
    return maximum - minimum;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    string a, b;
    cin >> a >> b;
    vector<vector<int>> values_after_index(n, vector<int>(26, 0));
    for (int i = 0; i < n; i++) {
        values_after_index[0][a[i] - 'a']++;
    }
    for (int i = 1; i <= n; i++) {
        values_after_index[i] = values_after_index[i - 1];
        values_after_index[i][a[i - 1] - 'a']--;
    }
    vector<int> values_in_b(26, 0);
    for (int i = 0; i < m; i++) {
        values_in_b[b[i] - 'a']++;
    }
    int answer = 0;
    vector<int> prev_values_in_b(values_in_b.begin(), values_in_b.end());
    for (int i = 0; i < m; i++) {
        values_in_b[b[i] - 'a']--;
        answer = max(answer, search(prev_values_in_b, values_in_b, values_after_index));
        prev_values_in_b = values_in_b;
    }
    printf("%d\n", answer);
    /* for (int i = 0; i <= n; i++) { */
    /*     printf("values after %d = \n", i); */
    /*     for (int j = 0; j < 26; j++) { */
    /*         printf("%c : %d\n", j + 'a', values_after_index[i][j]); */
    /*     } */
    /* } */
}
