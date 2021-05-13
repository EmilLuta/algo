#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> cities(n + 1);
    vector<int> k(n + 1);
    vector<long long> c(n + 1);
    set<int> visited;
    set<int> all;
    for (int i = 1; i <= n; i++) {
        all.insert(i);
    }
    set<int> built;
    vector<pair<int, int>> connections;
    for (int i = 1; i <= n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        cities[i] = {x, y};
    }
    long long output = 0;
    int min_index = 0;
    long long min_value = LLONG_MAX;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
        if (c[i] < min_value) {
            min_value = c[i];
            min_index = i;
        }
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &k[i]);
    }
    visited.insert(min_index);
    built.insert(min_index);
    all.erase(min_index);
    output += min_value;
    for (int unvisited_city : all) {
        min_index = 0;
        min_value = LLONG_MAX;
        bool light;
        for (int visited_city : visited) {
            long long wire_cost = (long long)(k[visited_city] + k[unvisited_city]) * (long long)(abs(cities[visited_city].first - cities[unvisited_city].first) + abs(cities[visited_city].second - cities[unvisited_city].second));
            if (c[unvisited_city] < min_value) {
                min_value = c[unvisited_city];
                min_index = unvisited_city;
                light = true;
            }
            if (wire_cost < min_value) {
                min_value = wire_cost;
                min_index = visited_city;
                light = false;
            }
        }
        visited.insert(min_index);
        output += min_value;
        if (light) {
            built.insert(unvisited_city);
        } else {
            connections.push_back({unvisited_city, min_index});
        }
    }
    printf("%d\n", output);
    printf("%d\n", built.size());
    for (int city : built) {
        printf("%d ", city);
    }
    printf("\n");
    printf("%d\n", connections.size());
    for (pair<int, int> connection : connections) {
        printf("%d %d\n", connection.first, connection.second);
    }
}
