class Sol{
public:
void findCombinations(int int, int target, vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds)
{
  if(target==0)
  {
ans.push_back(ds);
    return;
  }
  for(int i=ind;i<=arr.size();i++)
    {
       if(i>ind && arr[i]==arr[i-1]) continue;
      if(arr[i]>target) break;
      ds.push_back(arr[i]);
      findCombinations(i+1, target-arr[i], arr, ans,ds);
      ds.pop_back();
    }
}

vector<vector<int>> combination(vector<int>& nums, int target)
{
sort(nums.begin(), nums.end());
  vector<vector<int>> ans;
  vector<int> ds;
  findCombinations(0,target, nums, ans,ds);
  return ans;
}
};
