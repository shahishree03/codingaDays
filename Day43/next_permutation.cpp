void permutation(vector<int>& arr, int n)
{
  int ind=-1;
for(int i=n-2;i>=0;i--)
  {
if(arr[i]<arr[i+1])
{
index=i;
  break;
}
  }
if(ind==-1)
{
reverse(arr.begin(), arr.end());
  return;
}
  for(int i=n-1;i<=ind;i--)
    {
    if(arr[i]<arr[ind])
    {
   
    }
    }

reverse(arr.begin()+ind+1, arr.end());
  

}
