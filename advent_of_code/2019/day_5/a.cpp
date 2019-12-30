#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

vector<int> get_data(string data) {
    vector<int> output;
    string current_number = "";
    for (int i = 0; i < (int)data.size(); i++) {
        if ((data[i] >= '0' && data[i] <= '9') || data[i] == '-') {
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

vector<int> get_operation_and_modes(vector<int> &data, int i) {
    vector<int> output(5, 0);
    int x = data[i] / 100;
    output[0] = data[i] % 100;
    int k = 1;
    while (x > 0) {
        output[k] = x % 10;
        x /= 10;
        k++;
    }
    return output;
}

vector<int> get_values(vector<int> &data, vector<int> &operations_and_mode, int index, int n, int how_many) {
    vector <int> values(how_many, 0);
    for (int i = 1; i <= how_many; i++) {
        if (index + i < n) {
            if (operations_and_mode[i] == 1) {
                values[i - 1] = index + i;
            } else {
                if (data[index + i] < n) {
                    values[i - 1] = data[index + i];
                } else {
                    printf("Failed to get second level value at postion %d, offset %d\n", index + i, i);
                    exit(-1);
                }
            }
        } else {
            printf("Failed to get first level value at position %d, offset %d\n", index + i, i);
            exit(-1);
        }
    }
    return values;
}

int main() {
    ifstream input("input.txt");

    if (input.is_open()) {
        string input_data;
        getline(input, input_data);
        vector<int> data = get_data(input_data);
        int n = data.size();
        int i = 0;
        int inp;
        while (i < n) {
            vector<int> operation_and_modes = get_operation_and_modes(data, i);
            vector<int> values;
            switch (operation_and_modes[0]) {
                case 1:
                    values = get_values(data, operation_and_modes, i, n, 3);
                    data[values[2]] = data[values[1]] + data[values[0]];
                    i += 4;
                    break;
                case 2:
                    values = get_values(data, operation_and_modes, i, n, 3);
                    data[values[2]] = data[values[1]] * data[values[0]];
                    i += 4;
                    break;
                case 3:
                    values = get_values(data, operation_and_modes, i, n, 1);
                    cin >> inp;
                    data[values[0]] = inp;
                    i += 2;
                    break;
                case 4:
                    values = get_values(data, operation_and_modes, i, n, 1);
                    printf("%d\n", data[values[0]]);
                    i += 2;
                    break;
                case 99:
                    return 0;
                    break;
                default:
                    break;
            }
        }
        input.close();
        return 0;
    }
    printf("Unable to open file input.txt\n");
}
