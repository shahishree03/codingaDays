class Sol{
private:
void recurr(int index, vector<int>& nums, vector<vector<int>>& ans)
{
if(index==nums.size())
{
ans.push_back(nums);
}

  for(int i=0;i<nums.size();i++)
    {
      swap(nums[index], nums[i]);
      recurr(index+1, nums, ans);
      swap(nums[index], nums[i]);
    }

}

public:

vector<vcetor<int>> permute(vector<int>& nums)
{
vcetor<vector<int>> ans;
  recurr(0, nums, ans);
  return ans;
}

};

