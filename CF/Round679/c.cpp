#include <bits/stdc++.h>

using namespace std;

const int S = 6;
const int MAX_N = 1e5 + 5;

int values[MAX_N];
int s = 0;


void add(int x) {
    if (values[x] == 0) {
        s++;
    }
    values[x]++;
}

void remove(int x) {
    if (values[x] == 1) {
        s--;
    }
    values[x]--;
}

int size() {
    /* int c = 0; */
    /* for (int i = 0; i < MAX_N; i++) { */
    /*     if (values[i] > 0) { */
    /*         c++; */
    /*     } */
    /* } */
    /* return c; */
    return s;
}

int main() {
    vector<int> a(S);
    for (int i = 0; i < S; i++) {
        scanf("%d", &a[i]);
    }
    int n;
    scanf("%d", &n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    int notes_n = n * S;
    vector<pair<int, int>> notes(notes_n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < S; j++) {
            notes[i * S + j] = {b[i] - a[j], i};
        }
    }
    sort(notes.begin(), notes.end());
    int i = 0, j = 0;
    int answer = INT_MAX;
    while (i < notes_n) {
        if (size() < n && j < notes_n) {
            add(notes[j].second);
            j++;
        } else {
            if (size() == n) {
                answer = min(answer, notes[j - 1].first - notes[i].first);
            }
            remove(notes[i].second);
            i++;
        }
    }
    printf("%d\n", answer);
}
