#include <iostream>
#include <cmath>
#include <unordered_map>

using namespace std;

int main() {
    int groups_num;
    cin >> groups_num;

    unordered_map<string, int> not_full_groups_count;
    not_full_groups_count["1"] = 0;
    not_full_groups_count["2"] = 0;
    not_full_groups_count["3"] = 0;

    int total_cars_needed = 0;

    for (int i = 0; i < groups_num; ++i) {
        string group;
        cin >> group;

        if (group == "4") {
            total_cars_needed += 1;
        } else {
            not_full_groups_count[group] += 1;
        }
    }

    while (not_full_groups_count["3"] != 0) {
        not_full_groups_count["3"] -= 1;
        total_cars_needed += 1;

        if (not_full_groups_count["1"] != 0) {
            not_full_groups_count["1"] -= 1;
        }
    }

    while (not_full_groups_count["2"] > 1) {
        not_full_groups_count["2"] -= 2;
        total_cars_needed += 1;
    }

    if (not_full_groups_count["2"] == 1) {
        not_full_groups_count["1"] += 2;
    }

    if (0 < not_full_groups_count["1"] && not_full_groups_count["1"] < 4) {
        total_cars_needed += 1;
    } else {
        total_cars_needed += ceil(not_full_groups_count["1"] / 4.0);
    }

    cout << total_cars_needed << endl;

    return 0;
}
