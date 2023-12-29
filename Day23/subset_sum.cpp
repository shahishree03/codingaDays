#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> stackstorage;

void doSomething(vector<int>& v, int pos, int sum, vector<int>& temp)
{
    if (sum == 0)
    {
        stackstorage.push_back(temp);
        return;
    }

    for (int i = pos; i < v.size(); i++)
    {
        temp.push_back(v[i]);
        doSomething(v, i + 1, sum - v[i], temp);
        temp.pop_back();
    }
}

int main()
{
    vector<int> v = {2, 7, 11, 15, 5, 3, 0, 9, 1, 28, 7, -19, 11, 29, 45};
    int targetSum = 9;

    vector<int> temp;
    doSomething(v, 0, targetSum, temp);

    for (auto& subset : stackstorage)
    {
        int subsetSum = 0;
        for (auto& element : subset)
        {
            subsetSum += element;
        }

        if (subsetSum == targetSum)
        {
            cout << "[";
            for (size_t i = 0; i < subset.size(); i++)
            {
                cout << subset[i];
                if (i < subset.size() - 1)
                    cout << ", ";
            }
            cout << "]" << endl;
        }
    }

    return 0;
}
