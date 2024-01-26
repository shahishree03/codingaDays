class Sol
{
private:
void find(int ind, vector<int> &nums, vector<int> &ds, vector<vector<int>> ds)
{
ans.push_back(ds);
for(int i=ind;i<nums.size();i++)
{
if(i!=ind && nums[i]==nums[i-1]) continue;
ds.push_back(nums[i]);
find(i+1,nums, ds, ans);
ds.pop_back();
}

}

vector<vector<int>> f(vector<int>& nums, int n, int sum)
{
vector<int> ds;
vector<vector<int>> ans;
 sort(nums.begin(), nums.end());
find(0, nums, ds, ans);
return ans;

}
};
