#include <bits/stdc++.h>

using namespace std;

vector<int> solve1(vector<int> arr) {
    int product = 1;
    for (int i = 0; i < arr.size(); i++) {
        product *= arr[i];
    }
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = product / arr[i];
    }
    return arr;
}

vector<int> solve2(vector<int> arr) {
    vector<int> fw(arr.size()), bw(arr.size());
    for (int i = 0; i < arr.size(); i++) {
        int j = arr.size() - i - 1;
        if (i == 0) {
            fw[i] = 1;
            bw[j] = 1;
            continue;
        }
        fw[i] = fw[i - 1] * arr[i - 1];
        bw[j] = bw[j + 1] * arr[j + 1];
    }
	for (int i = 0; i < arr.size(); i++) {
		arr[i] = fw[i] * bw[i];
	}
    return arr;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
   	vector<int> a1 = solve1(arr);
    vector<int> a2 = solve2(arr);
	for (int i = 0; i < arr.size(); i++) {
        printf("%d ", a1[i]);
    }
    printf("\n");
    for (int i = 0; i < arr.size(); i++) {
        printf("%d ", a2[i]);
    }
    printf("\n");
    for (int i = 0; i < arr.size(); i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
