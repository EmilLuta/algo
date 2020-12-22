#include <bits/stdc++.h>

using namespace std;

pair<long long, vector<int>> merge_and_count_split_inv(vector<int> a) {
    int n = a.size();
    if (n == 1 || n == 0) {
        return {0, a};
    }
    int half = n / 2;
    vector<int>(a.begin(), a.begin() + half);
    vector<int>(a.begin() + half, a.end());

    pair<long long, vector<int>> left = merge_and_count_split_inv(vector<int>(a.begin(), a.begin() + half));
    pair<long long, vector<int>> right = merge_and_count_split_inv(vector<int>(a.begin() + half, a.end()));
    int i = 0, j = 0, left_n = left.second.size(), right_n = right.second.size();
    pair<long long, vector<int>> answer;
    answer.first = left.first + right.first;
    while (i < left_n && j < right_n) {
        if (left.second[i] > right.second[j]) {
            answer.second.push_back(right.second[j]);
            j++;
            answer.first += left_n - i;
        } else {
            answer.second.push_back(left.second[i]);
            i++;
        }
    }
    if (i != left_n) {
        for (int k = i; k < left_n; k++) {
            answer.second.push_back(left.second[k]);
        }
    }
    if (j != right_n) {
        for (int k = j; k < right_n; k++) {
            answer.second.push_back(right.second[k]);
        }
    }
    return answer;
}

int main() {
    freopen("in.txt", "r", stdin);
    int n = 100000;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }
    pair<long long, vector<int>> answer = merge_and_count_split_inv(x);
    for (int i = 0; i < n; i++) {
        printf("%d ", answer.second[i]);
    }
    printf("\n");
    printf("%lld\n", answer.first);
}
