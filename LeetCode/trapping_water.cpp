#include <bits/stdc++.h>

using namespace std;

void sum_until_max(const vector<int> &height, int &water, const int max_index) {
    int current_max = 0;
    int i = 0;
    for(i = 0; i < max_index; i++) {
        current_max = max(current_max, height[i]);
        water += current_max - height[i];
    }
}

int trap(vector<int> height) {
    int n = height.size();
    if (n == 0) {
        return 0;
    }
    int max_index = 0;
    for(int i = 0; i < n; i++) {
        if(height[i] >= height[max_index]) {
            max_index = i;
        }
    }
    int water = 0;
    sum_until_max(height, water, max_index);
    reverse(height.begin(), height.end());
    max_index = n - 1 - max_index;
    sum_until_max(height, water, max_index);
    return water;
}


int main() {

    // int answer = trap({0,1,0,2,1,0,1,3,2,1,2,1}); // 6
    int answer = trap({4, 0, 0, 0, 4, 2, 4, 0, 3, 2, 1}); // 17
    /* int answer = trap({4, 0, 0, 0, 4, 2}); // 12 */
    cout << answer << endl; // should be 6
    // 1) read the code (again) -> logic & implementation errors
    // 2) print what your codes does
    // 3) try to find a smaller counter-test
    
}




