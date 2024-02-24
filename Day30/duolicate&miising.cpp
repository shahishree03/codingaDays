#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void using_swap(vector<int>& arr)
{
     int missing, dup;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]-1!=i)
        {
            if(arr[i]!=arr[arr[i]]-1)
             swap(arr[i], arr[arr[i]-1]);
             else
             {
                 dup=arr[i];
                 continue;
             }
             
         }
         else{
             missing=i;
         }
    }
    
   cout<<missing<<" "<<dup<<" ";
}
int main()
{
    vector<int> arr={2,3,1,5,1};
   // sort(arr.begin(), arr.end());
   using_swap(arr);
    
}
