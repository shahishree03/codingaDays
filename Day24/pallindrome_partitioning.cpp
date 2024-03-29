class Sol
{

vector<vector<string>> partition(string s)
{
vector<vector<string>> ans;
  vector<string> path;
  func(0, s, path , res);
  return ans;
}

void func(int ind, string s, vector<string>& path , vector<vector<string>>& res)
{
  if(index==s.size())
  {
   res.push_back(path);
    return;
  }
  for(int i=index;i<s.size();i++)
    {
if(isPallindrome(s, index, i))
{
path.push_back(s.substr(index, i-index+1));
  func(i+1, s, path , res);
  path.pop_back();
}
    }
}

bool isPallindrome(string s, int start , int end)
{
while(start<=end)
  {
   if(s[start++]!=s[end--])
      return false;
  }
  return true;
}
};
