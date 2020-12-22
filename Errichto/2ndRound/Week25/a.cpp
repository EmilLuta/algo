#include <bits/stdc++.h>

using namespace std;

struct CounterMap {
    CounterMap() : values(), count(0) {} // perhaps the most confusing thing ever.
    void update(int val, int by_what) {
        if (this->values[val] != 0) this->count--;
        this->values[val] += by_what;
        if (this->values[val] != 0) this->count++;
    }

    int size() {
        return this->count;
    }

    private:
        map<int, int> values;
        int count;
};


struct CounterVector {
    CounterVector() : values(pow(10, 6) + 1), count(0) {} // perhaps the most confusing thing ever x 2.
    void update(int val, int by_what) {
        if (this->values[val] != 0) this->count--;
        this->values[val] += by_what;
        if (this->values[val] != 0) this->count++;
    }

    int size() {
        return this->count;
    }

    private:
        vector<int> values;
        int count;
};

vector<int> distinct_for_interval_of_size(vector<int>& a, int k) {
    int n = a.size();
    assert(n >= k);
    vector<int> answer(n - k + 1);
    CounterVector c;
    for (int i = 0; i < k; i++) {
        c.update(a[i], +1);
    }
    answer[0] = c.size();
    for (int i = k; i < n; i++) {
        c.update(a[i - k], -1);
        c.update(a[i], +1);
        answer[i - k + 1] = c.size();
    }
    return answer;
}

int main() {
    vector<int> a = {5, 2, 5, 10, 4, 2};
    int k = 3;
    vector<int> out = distinct_for_interval_of_size(a, k);
    for (int i = 0; i < (int)out.size(); i++) {
        printf("%d ", out[i]);
    }
    printf("\n");
}
