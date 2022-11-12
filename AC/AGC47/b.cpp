#include <bits/stdc++.h>

using namespace std;

int INDEX = 0;

struct Node {
    vector<Node> children;
    int id;
    bool is_leaf;
    bool is_init;
};

Node new_node() {
    INDEX++;
    return Node {vector<Node>(26), INDEX - 1, false, true};
}

int N = 1000000;

int cache[1000000][26][2];

int dfs(Node* node, int char_index, bool matched) {
    if (cache[node->id][char_index][matched] != -1) {
        return cache[node->id][char_index][matched];
    }
    int answer = 0;
    if (node->is_leaf && matched) {
        answer++;
    }
    for (int i = 0; i < 26; i++) {
        if (node->children[i].is_init) {
            answer += dfs(&node->children[i], char_index, matched || i == char_index);
        }
    }
    cache[node->id][char_index][matched] = answer;
    return answer;
}

int main() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 26; j++) {
            for (int k = 0; k < 2; k++) {
                cache[i][j][k] = -1;
            }
        }
    }
    int n;
    scanf("%d", &n);
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        reverse(a[i].begin(), a[i].end());
    }
    Node trie = new_node();
    int answer = 0;
    for (string s : a) {
        Node* curr_node = &trie;
        int n_s = s.size();
        for (int i = 0; i < n_s; i++) {
            int index = s[i] - 'a';
            if (!curr_node->children[index].is_init) {
                curr_node->children[index] = new_node();
            }
            curr_node = &curr_node->children[index];
        }
        curr_node->is_leaf = true;
    }
    for (string s : a) {
        Node* node = &trie;
        int n_s = s.size();
        bool can_match = true;
        for (int i = 0; i < n_s - 1; i++) {
            int index = s[i] - 'a';
            if (!node->children[index].is_init) {
                break;
                can_match = false;
            }
            node = &node->children[index];
        }
        if (can_match) {
            answer += dfs(node, s[n_s - 1] - 'a', false);
            answer--;
        }
    }
    printf("%d\n", answer);
}
