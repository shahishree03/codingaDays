class Sol
{
public:
//int count=0;
void merge(vector<int& arr, int low, int mid, int high)
{
vector<int> ans;
 int count=0;
  int left=low, right=mid+1;
  while(left<=mid && right<=high)
    {
    if(arr[left]<=arr[right])
    {
    temp.push_back(arr[left]);
      left++;
    }
      else
    {
 temp.push_back(arr[right]);
       count+=(mid-left+1);
      right++;
     
    }

    }
while(left<=mid)
  {
temp.push_back(arr[left]);
    left++;
   
  }

  while(right<=high)
    {

temp.push_back(arr[right]);
      right++;
     // count++;
      
    }
  return count;
  
}
int mergesort(vector<int>& arr, int low, int high)
{
int count=0;
  if(low>=high)
  {
   return;
  }
  int mid=(low+high/2;
  count+=mergesort(arr, low, mid);
  count+=mergesort(arr, mid+1, high);
   count+=merge(arr, low, mid, high);
  return count;

}

int countInversion(vector<int>& nums, int n)
{
return mergesort(vector<int>&nums, 0, n-1);
  //return count;
}
};
