class Sol
{
private:
void recurr(vector<int>& nums, vector<int>& ds, vector<vector<int>> & ans, int freq[])
{
if(ds.size() ==nums.size()){
ans.push_back(ds);
  return;
}
  for(int i=0;i<nums.size();i++)
    {
     if(!freq[i])
     {
     ds.push_back(nums[i]);
       freq[i]=1;
       //just add------------>
       recurr(ds, nums, ans, freq);
       //recurr for other 
       freq[i]=0;
       //remove and do for others
       ds.pop_back();
     }
    }

}

public:
vector<vector<int>> permute(vector<int>& nums)
{
vector<vector<int>> ans;
  vector<int> ds;
  int fre[nums.size()] ={0};
  recurr(ds, nums, ans, freq)'
    return ans;
}
};

