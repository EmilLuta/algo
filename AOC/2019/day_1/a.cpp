#include <bits/stdc++.h>

using namespace std;

void compute_fuel(int current_fuel, int &fuel) {
    current_fuel = current_fuel / 3 - 2;
    if (current_fuel <= 0) {
        return;
    }
    fuel += current_fuel;
    compute_fuel(current_fuel, fuel);
}

int main() {
    ifstream input("input.txt");
    int sum = 0;
    if (input.is_open()) {
        string line;
        while (getline (input, line)) {
            int current_number = stoi(line);
            int fuel = 0;
            compute_fuel(current_number, fuel);
            sum += fuel;
        }
        input.close();
        printf("%lld\n", sum);
        return 0;
    }
    printf("Unable to open file input.txt\n");
}
