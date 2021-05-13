#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int nn = n;
    vector<int> a;
    set<int> seen;
    map<int, int> counter;
    for (int i = 0; i < n; i++) {
        int item;
        scanf("%d", &item);
        if (seen.count(item) == 0) {
            a.push_back(item);
            seen.insert(item);
        }
        counter[item]++;
    }
    sort(a.begin(), a.end());
    n = (int)a.size();
    int i = 0;
    int minimum = 0;
    while (i < n - 2) {
        if ((a[i] + 1 == a[i + 1]) && (a[i + 1] + 1 == a[i + 2])) {
            i += 3;
        } else if (a[i] + 1 == a[i + 1] || a[i] + 2 == a[i + 1]) {
            i += 2;
        } else {
            i++;
        }
        minimum += 1;
    }
    if (n - i == 2) {
        if (a[i] + 1 == a[i + 1] || a[i] + 2 == a[i + 1]) {
            minimum += 1;
        } else {
            minimum += 2;
        }
    } else if (n - i == 1) {
        minimum++;
    }
    set<int> visited;
    for (pair<int, int> key_value : counter) {
        int item = key_value.first;
        if (visited.count(item - 1) == 0 && counter[item] > 0) {
            visited.insert(item - 1);
            counter[item]--;
        }
        if (counter[item] > 0 && visited.count(item) == 0) {
            visited.insert(item);
            counter[item]--;
        }
        if (visited.count(item + 1) == 0 && counter[item] > 0) {
            visited.insert(item + 1);
            counter[item]--;
        }
    }
    printf("%d %d\n", minimum, (int)visited.size());
}
