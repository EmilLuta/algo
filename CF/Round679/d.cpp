#include <bits/stdc++.h>

using namespace std;

class Option {
    private:
        int val = -1;
    public:
        Option() {}

        void read() { // TODO: Discuss about reading from keyboard;
            char option;
            scanf(" %c", &option);
            if (option == '-') {
                scanf("%d", &val);
            }
        }

        bool is_add() {
            return val == -1;
        }

        int value() {
            assert(val != -1);
            return val;
        }

        string str() {
            return "Option<'" + to_string(val) + "'>";
        }
};

int main() {
    int n;
    scanf("%d", &n);
    vector<Option> a(n * 2);
    set<int> unshown, unsettled;
    map<int, int> rev_map;
    for (int i = 0; i < 2 * n; i++) {
        a[i].read();
        if (i >= 1 && i <= n) {
            unshown.insert(i);
        }
    }
    int displayed = 0;
    vector<int> answer(n);
    int index = 0;
    for (Option o : a) {
        if (o.is_add()) {
            if (unshown.size() == 0) {
                printf("NO\n");
                return 0;
            }
            int val = *unshown.rbegin();
            unshown.erase(val);
            answer[index] = val;
            rev_map[val] = index;
            unsettled.insert(val);
            index++;
            continue;
        }
        if (unsettled.size() == 0) {
            printf("NO\n");
            return 0;
        }
        int low = *unsettled.begin();
        if (low < o.value()) {
            printf("NO\n");
            return 0;
        }
        if (low == o.value()) {
            unsettled.erase(low);
        } else {
            assert(unshown.count(o.value()) != 0);
            unshown.erase(o.value());
            unsettled.erase(low);
            unshown.insert(low);
            answer[rev_map[low]] = o.value();
        }
    }
    set<int> verify;
    int curr_index = 0;
    for (int i = 0; i < n * 2; i++) {
        if (a[i].is_add()) {
            verify.insert(answer[curr_index]);
            curr_index++;
        } else {
            int val = *verify.begin();
            if (val != a[i].value()) {
                printf("NO\n");
                return 0;
            }
            verify.erase(val);
        }
    }
    printf("YES\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", answer[i]);
    }
    printf("\n");
}
