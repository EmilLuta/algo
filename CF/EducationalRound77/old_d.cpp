#include <bits/stdc++.h>

using namespace std;

int main() {
    int m, n, k, t;
    scanf("%d %d %d %d", &m, &n, &k, &t);
    vector<int> agility(m);
    vector<pair<int, int>> trap(k);
    for (int i = 0; i < m; i++) {
        scanf("%d", &agility[i]);
    }
    for (int i = 0; i < k; i++) {
        int start, end, danger;
        scanf("%d %d %d", &start, &end, &danger);
        trap[i] = {end, danger};
    }
    if ((n + 1)* 3 < t) {
        printf("%d\n", m);
        return 0;
    }
    sort(trap.begin(), trap.end());
    int so_far = (t - n) / 2;
    /* printf("so_far = %d\n", so_far); */
    int danger_index = 0;
    for (int i = 1; i <= so_far; i++) {
        while (trap[danger_index].first == i && danger_index < k) {
            danger_index++;
        }
        if (danger_index == k) {
            printf("%d\n", m);
            return 0;
        }
    }
    /* printf("traps : \n"); */
    /* for (int i = 0; i < k; i++) { */
        /* printf("trap ending at %d with value %d\n", trap[i].first, trap[i].second); */
    /* } */
    /* printf("\n"); */
    /* printf("danger_index = %d\n", danger_index); */
    int danger_level = trap[danger_index].second;
    for (int i = danger_index + 1; i < k; i++) {
        danger_level = max(danger_level, trap[i].second);
    }
    int output = 0;
    /* printf("danger_level = %d\n", danger_level); */
    for (int i = 0; i < m; i++) {
        if (agility[i] >= danger_level) {
            output++;
        }
    }
    printf("%d\n", output);
}
