#include<iostream>
#include<vector>
using namespace std;
bool subset_Sum(vector<int>& arr, int n , int target)
{
    bool subset[n+1][target+1];
    for(int i=0;i<=n;i++)
        subset[i][0]= true;
        
    for(int i=0;i<=n;i++)
    subset[0][i]=false;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=target ;j++)
        {
            if(j>=arr[i-1])
              subset[i][j]=subset[i-1][j] || subset[i-1][j-arr[i-1]];
              
        
        else  
        {
            subset[i][j]= subset[i-1][j];
        }
        }
    }
    return subset[n][target];
    
    }
int main()
{
    vector<int> arr={3,34, 4, 12,5, 2};
    int target= 9;
    
    if(subset_Sum(arr, arr.size() , target)==true)
{
    cout<<"trturn true"<<endl;
}    
    
}
