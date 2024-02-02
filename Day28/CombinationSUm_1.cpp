class Solution {
    private:

    void combinations(vector<int>& arr, int ind,int sum, vector<vector<int>>& ans, vector<int>& temp)
    {
        if(ind==arr.size())
        {
            if(sum==0) {
            ans.push_back(temp);}
            return;
        }
        if(arr[ind]<=sum)
        {
            temp.push_back(arr[ind]);
            combinations(arr, ind,sum-arr[ind], ans, temp);
            temp.pop_back();
        }
        combinations(arr, ind+1,sum, ans, temp);
        
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        combinations(candidates, 0,target,  ans, temp);
return ans;
        
    }
};
