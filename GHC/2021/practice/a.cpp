#include <bits/stdc++.h>

using namespace std;

struct Pizza {
    int id;
    set<string> ingredients;

    int get_ingredient_no() {
        return this->ingredients.size();
    }

    void read(ifstream& f, int pizza_id) {
        this->id = pizza_id;
        int n;
        f >> n;
        for (int i = 0; i < n; i++) {
            string ingredient;
            f >> ingredient;
            this->ingredients.insert(ingredient);
        }
    }

    string to_string() {
        string pizza = "";
        pizza += "Pizza #" + ::to_string(id) + " with ingredients: {";
        bool first_pizza = true;
        for (string ingredient : this->ingredients) {
            if (!first_pizza) {
                pizza += ", ";
            }
            pizza += ingredient;
            first_pizza = false;
        }
        pizza += "}";
        return pizza;
    }
};

vector<vector<int>> solve_strategy_one(vector<Pizza>& pizzas, set<int> pizzas_left, int two, int three, int four) {
    vector<vector<int>> output;
    while (two > 0) {
        if (pizzas_left.size() >= 2) {
            int pizza_id_1 = *pizzas_left.begin();
            pizzas_left.erase(pizzas_left.begin());
            int pizza_id_2 = *pizzas_left.begin();
            pizzas_left.erase(pizzas_left.begin());
            output.push_back({pizza_id_1, pizza_id_2});
            two--;
        } else {
            break;
        }
    }
    while (three > 0) {
        if (pizzas_left.size() >= 3) {
            int pizza_id_1 = *pizzas_left.begin();
            pizzas_left.erase(pizzas_left.begin());
            int pizza_id_2 = *pizzas_left.begin();
            pizzas_left.erase(pizzas_left.begin());
            int pizza_id_3 = *pizzas_left.begin();
            pizzas_left.erase(pizzas_left.begin());
            output.push_back({pizza_id_1, pizza_id_2, pizza_id_3});
            three--;
        } else {
            break;
        }
    }
    while (four > 0) {
        if (pizzas_left.size() >= 4) {
            int pizza_id_1 = *pizzas_left.begin();
            pizzas_left.erase(pizzas_left.begin());
            int pizza_id_2 = *pizzas_left.begin();
            pizzas_left.erase(pizzas_left.begin());
            int pizza_id_3 = *pizzas_left.begin();
            pizzas_left.erase(pizzas_left.begin());
            int pizza_id_4 = *pizzas_left.begin();
            pizzas_left.erase(pizzas_left.begin());
            output.push_back({pizza_id_1, pizza_id_2, pizza_id_3, pizza_id_4});
            four--;
        } else {
            break;
        }
    }

    return output;
}

vector<vector<int>> solve_strategy_two(vector<Pizza>& pizzas, int two, int three, int four, unordered_set<int> pizzas_left) {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    auto it = pizzas_left.begin();
    while ((two + three + four != 0) && (pizzas_left.size() >= 2)) {
        int pick = rng() % 3;
        switch (pick) {
            case 0:
                if (pizzas_left.size() >= 2) {
                    rng() % (int)pizzas_left.size();
                }
                break;
            case 1:
                break;
            case 2:
                break;
            default:
                cout << "WTF?" << endl;
                exit(0);
        }
        if (pizzas_left.size()
    }
}

void solve(vector<Pizza>& pizzas, int two, int three, int four, string filename) {
    ofstream out("out_" + filename);
    int n = pizzas.size();
    unordered_set<int> pizzas_left;
    for (int i = 0; i < n; i++) {
        pizzas_left.insert(i);
    }
    /* vector<vector<int>> output = solve_strategy_one(pizzas, pizzas_left, two, three, four); */
    vector<vector<int>> output = solve_strategy_two(pizzas, two, three, four, pizzas_left);
    int m = output.size();
    out << m << endl;
    for (int i = 0; i < m; i++) {
        int o = output[i].size();
        out << o << " ";
        for (int j = 0; j < o; j++) {
            out << output[i][j] << " ";
        }
        out << "\n";
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        cout << "Use this as './bin input_file'. Your missing another parameter, the input_file.\n";
        return 0;
    }
    for (int x = 1; x < argc; x++) {
        ifstream f(argv[x]);
        if (!f.is_open()) {
            cout << "Couldn't open file: '" << argv[x] << "'\n";
            return 0;
        }
        int n, two, three, four;
        f >> n >> two >> three >> four;
        vector<Pizza> pizzas(n);
        for (int i = 0; i < n; i++) {
            Pizza pizza = Pizza{};
            pizza.read(f, i);
            pizzas[i] = pizza;
        }
        solve(pizzas, two, three, four, string(argv[x]));
        f.close();
    }
}
