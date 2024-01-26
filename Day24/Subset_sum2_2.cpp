class Sol{
void f(vector<int>& nums, int ind ,vector<vector<int>>& ans)
{
 if(ind==nums.size()){
ans.push_back(nums);
   return;
 }
  for(int i=ind;i<nums.size();i++)
    {
     swap(nums[ind], nums[i]);
      f(ind+1, nums, ans);
      swap(nums[ind], nums[i]);
    }
}

public:
vector<vector<int>> fun(vector<int>& nums, int N)
{
 vector<vector<int>> & ans;
  f(nums, 0, N, ans);
  return ans;
}

};
