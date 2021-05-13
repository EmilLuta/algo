#include <bits/stdc++.h>

using namespace std;

map<int, vector<vector<int>>> counter;
set<int> covered;

void get_y_z(const int &x, int &y, int &z) {
    vector<int> values = counter[x][0];
    if (values[0] == x) {
        y = values[1];
        z = values[2];
    } else if (values[1] == x) {
        y = values[0];
        z = values[2];
    } else {
        y = values[0];
        z = values[1];
    }
}

void get_z(const int x, const int y, int &z) {
    for (vector<int> triplet : counter[x]) {
        bool found_x = false, found_y = false;
        for (int value : triplet) {
            if (value == x) {
                found_x = true;
            }
            if (value == y) {
                found_y = true;
            }
        }
        if (found_x && found_y) {
            for (int i = 0; i <= 2; i++) {
                if (triplet[i] != x && triplet[i] != y) {
                    z = triplet[i];
                }
            }
            if (covered.count(z) == 0) {
                return;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> output;
    for (int i = 0; i < n - 2; i++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        vector<int> values{x, y, z};
        counter[x].push_back(values);
        counter[y].push_back(values);
        counter[z].push_back(values);
    }
    int start;
    for (int i = 1; i <= n; i++) {
        if ((int)counter[i].size() == 1) {
            start = i;
            break;
        }
    }
    vector<int> triplet = counter[start][0];
    int x, y, z;
    x = start;
    output.push_back(x);
    covered.insert(x);
    get_y_z(x, y, z);
    if ((int)counter[y].size() == 2) {
        output.push_back(y);
        covered.insert(y);
    } else {
        output.push_back(z);
        covered.insert(z);
        swap(y, z);
    }
    for (int i = 3; i <= n - 2; i++) {
         output.push_back(z);
         covered.insert(z);
         x = y;
         y = z;
         get_z(x, y, z);
    }
    bool found_y = false, found_z = false;
    for (int i = 1; i <= n; i++) {
        if (covered.count(i) == 0) {
            if (found_y) {
                z = i;
                break;
            } else {
                y = i;
                found_y = true;
            }
        }
    }
    if ((int)counter[y].size() == 2) {
        output.push_back(y);
        output.push_back(z);
    } else {
        output.push_back(z);
        output.push_back(y);
    }
	for (int o : output) {
		printf("%d ", o);
	}
	printf("\n");
}
