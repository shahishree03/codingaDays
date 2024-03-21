#include<iostream>
#include<vector>
using namespace std;


int main()
{
    vector<int> arr={10, 22, 12, 3, 0, 6};
    vector<int> ans;
     int max = arr[5];
    ans.push_back(arr[5]);
    for(int i=4;i>=0;i--)
    {
        if(arr[i]>max)
        {
            
            ans.push_back(arr[i]);
            max=arr[i];
        }
    }
     for(int i = ans.size()-1;i>=0;i--){
      
      cout<<ans[i]<<" ";
     }
    
}
