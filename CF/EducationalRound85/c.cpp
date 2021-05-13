#include<bits/stdc++.h>

using namespace std;

int get_next(int i, int n) {
    return (i + 1) % n;
}

int get_prev(int i, int n) {
    if (i == 0) {
        return n - 1;
    }
    return i - 1;
}

long long min_ll(long long a, long long b) {
    if (a > b) {
        return b;
    }
    return a;
}

long long get_damage(int i, vector<pair<long long, long long>> &a, int n) {
    printf("%d\n", i);
    printf("muie\n");
    int next_index = get_next(i, n);
    printf("la\n");
    int prev_index = get_prev(i, n);
    printf("next_index = %d, i = %d\n", next_index, i);
    a[next_index].first;
    a[i].second;
    printf("woot\n");
    min_ll(a[next_index].first, a[i].second);
    printf("statuie\n");
    return a[i].first + min(a[next_index].first, a[i].second) + min(a[prev_index].first, a[i].second);

}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        t--;
        int n;
        scanf("%d", &n);
        vector<pair<long long, long long>> a(n);
        for (int i = 0; i < n; i++) {
            long long x, y;
            scanf("%lld %lld", &x, &y);
            a[i] = {x, y};
        }
        set<pair<long long, int>> damage_queue;
        for (int i = 0; i < n; i++) {
            damage_queue.insert({get_damage(i, a, n), i});
        }
        for (auto i : damage_queue) {
            printf("%lld -> %d\n", i.first, i.second);
        }
        long long total = 0;
        int taken_out = 0;
        while (taken_out != n) {
            pair<long long, int> current = *damage_queue.end();
            printf("damage = %lld, index = %d", current.first, current.second);
            int index = current.second;
            long long damage = get_damage(index, a, n);
            if (damage == current.first) {
                int prev_index = get_prev(index, n);
                int next_index = get_next(index, n);
                total += a[index].first;
                a[index].first = 0;
                taken_out += 1;
                a[prev_index].first = max((long long)0, a[prev_index].first - damage);
                a[next_index].first = max((long long)0, a[next_index].first - damage);
                if (a[prev_index].first == 0) {
                    taken_out += 1;
                }
                if (a[next_index].first == 0) {
                    taken_out += 1;
                }
				damage_queue.erase(damage_queue.end());
            } else {
                printf("mare\n");
				damage_queue.erase(damage_queue.end());
                damage_queue.insert({damage, index});
            }
			printf("pula mea\n");
        }
        printf("%lld\n", total);
    }
}
