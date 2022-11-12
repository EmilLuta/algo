#include <bits/stdc++.h>

using namespace std;

int get_start_node(vector<vector<int>>& starts, vector<vector<int>>& ends, vector<bool>& seen) {
    int node = -1;
    for (int i = 0; i < 26; i++) {
        int starts_no = starts[i].size();
        int ends_no = ends[i].size();
        if (starts_no == 1 && ends_no == 0 && !seen[starts[i][0]]) {
            return starts[i][0];
        }
    }
    for (int i = 0; i < (int)seen.size(); i++) {
        if (!seen[i]) {
            return i;
        }
    }
    return node;
}

int get_next_node(vector<vector<int>>& starts, vector<vector<int>>& ends, vector<bool>& seen, char continue_from) {
    if (continue_from == ' ') {
        return get_start_node(starts, ends, seen);
    }
    if (starts[continue_from - 'A'].size() != 0) {
        for (int node : starts[continue_from - 'A']) {
            if (!seen[node]) {
                return node;
            }
        }
    }
    return get_start_node(starts, ends, seen);
}

vector<string> preprocess() {
    vector<vector<int>> same_chars(26);
    int n;
    scanf("%d", &n);
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        char same_char = s[i][0];
        bool unique = true;
        for (char c : s[i]) {
            if (c != same_char) {
                unique = false;
                break;
            }
        }
        if (unique) {
            same_chars[same_char - 'A'].push_back(i);
        }
    }
    for (int c = 0; c < 26; c++) {
        int sc_n = same_chars[c].size();
        if (sc_n > 1) {
            int to_add_index = same_chars[c][0];
            for (int i = 1; i < sc_n; i++) {
                s[to_add_index] += s[same_chars[c][i]];
                s[same_chars[c][i]] = "";
            }
            same_chars[c] = {to_add_index};
        }
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == "") {
            continue;
        }
        int c_index = s[i][0] - 'A';
        bool updated = false;
        string buffer = "";
        for (int index : same_chars[c_index]) {
            if (index == i) {
                continue;
            }
            buffer += s[index];
            s[index] = "";
            updated = true;

        }
        if (updated) {
            s[i] = buffer + s[i];
            same_chars[c_index] = {};
        }
        int s_n = s[i].size();
        c_index = s[i][s_n - 1] - 'A';
        updated = false;
        for (int index : same_chars[c_index]) {
            if (index == i) {
                continue;
            }
            s[i] += s[index];
            s[index] = "";
            updated = true;
        }
        if (updated) {
            same_chars[c_index] = {};
        }
    }
    vector<string> out;
    for (string& str : s) {
        if (str.size() > 0) {
            out.push_back(str);
        }
    }
    return out;
}

string solve() {
    vector<string> s = preprocess();
    int N = s.size();
    vector<int> n(N);
    vector<vector<int>> starts(26), ends(26);
    for (int i = 0; i < N; i++) {
        n[i] = s[i].size();
        starts[s[i][0] - 'A'].push_back(i);
        ends[s[i][n[i] - 1] - 'A'].push_back(i);
    }
    vector<bool> seen(N, false);
    int node_count = 0;
    char prev_char = ' ';
    string out = "";
    while (node_count < N) {
        int node = get_next_node(starts, ends, seen, prev_char);
        if (node == -1) {
            return "IMPOSSIBLE";
        }
        seen[node] = true;
        out += s[node];
        prev_char = s[node][n[node] - 1];
        node_count++;
    }
    int out_n = out.size();
    int i = 1;
    vector<bool> used(26, false);
    while (i < out_n) {
        if (out[i - 1] != out[i]) {
            used[out[i - 1] - 'A'] = true;
            if (used[out[i] - 'A']) {
                return "IMPOSSIBLE";
            }
        }
        i++;
    }
    return out;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        string answer = solve();
        cout << "Case #" << i << ": " << answer << "\n";
    }
}
