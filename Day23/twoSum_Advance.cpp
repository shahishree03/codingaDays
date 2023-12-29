#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<pair<int, int>> doSomething(vector<int>& arr, int target)
{
    vector<pair<int, int>> vec;
    unordered_map<int, int> seen;

    for (int i = 0; i < arr.size(); ++i)
    {
        int complement = target - arr[i];

        if (seen.find(complement) != seen.end())
        {
            vec.push_back({seen[complement], i});
        }

        seen[arr[i]] = i;
    }

    return vec;
}

int main()
{
    vector<int> v = {2, 7, 11, 15, 0, 9, 28, 7, -19, 11, 29, 45};

    vector<pair<int, int>> v1 = doSomething(v, 9);
    for (auto i : v1)
    {
        cout << i.first << " " << i.second << " " << endl;
    }

    return 0;
}
