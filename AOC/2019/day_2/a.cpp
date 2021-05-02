#include <bits/stdc++.h>

using namespace std;

vector<int> get_data(string data) {
    vector<int> output;
    string current_number = "";
    for (int i = 0; i < (int)data.size(); i++) {
        if (data[i] >= '0' && data[i] <= '9') {
            current_number += data[i];
        } else {
            if ((int)current_number.size() == 0) {
                continue;
            }
            output.push_back(stoi(current_number));
            current_number = "";
        }
    }
    if ((int)current_number.size() != 0) {
        output.push_back(stoi(current_number));
    }
    return output;
}

int get_value(vector<int> &data, int index, int offset, int n) {
    if (index + offset < n && data[index + offset] < n) {
        return data[index + offset];
    } else {
        printf("Failed to get value at position %d, offset %d\n", index + offset, offset);
        exit(-1);
    }
}

int main() {
    ifstream input("input.txt");

    if (input.is_open()) {
        string input_data;
        getline(input, input_data);
        vector<int> initial_data = get_data(input_data);
        for (int noun = 0; noun < 100; noun++) {
            for (int verb = 0; verb < 100; verb++) {
                vector<int> data = initial_data;
                data[1] = noun;
                data[2] = verb;
                int n = data.size();
                int i = 0;
                int w = 0;
                while (i < n) {
                    int one, two, three;
                    switch (data[i]) {
                        case 1:
                            one = get_value(data, i, 1, n);
                            two = get_value(data, i, 2, n);
                            three = get_value(data, i, 3, n);
                            data[three] = data[one] + data[two];
                            i += 4;
                            break;
                        case 2:
                            one = get_value(data, i, 1, n);
                            two = get_value(data, i, 2, n);
                            three = get_value(data, i, 3, n);
                            data[three] = data[one] * data[two];
                            i += 4;
                            break;
                        case 99:
                            if (data[0] == 19690720) {
                                printf("noun = %d, verb = %d\n", noun, verb);
                                for (int number : data) {
                                    printf("%d,", number);
                                }
                                printf("\n");
                                return 0;
                                break;
                            }
                            i = INT_MAX;
                            break;
                        default:
                            break;
                    }
                }
            }
        }
        input.close();
        return 0;
    }
    printf("Unable to open file input.txt\n");
}
