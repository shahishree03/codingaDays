#include<iostream>
#include<vector>
using namespace std;
class Sol{
    public:
bool find_partition(vector<int>& arr, int n )
{
   int sum=0;
   int i, j;
   for(i=0;i<n;i++)
   {
       sum+=arr[i];
   }
   
   if(sum%2!=0)
   return false;
   
   bool part[sum/2+1][n+1];
   
   for(i=0;i<=n;i++)
   part[0][i]=true;
   
   for(i=1;i<=sum/2;i++)
   part[i][0]=false;
   
   for(i=1;i<=sum/2;i++)
   {
       for(j=1;j<=n;j++)
       {
           part[i][j]=part[i][j-1];
           if(i>=arr[j-1])
           part[i][j]=part[i][j] || part[i-arr[j-1]][j-1]; 
       }
   }
   
   return part[sum/2][n];
    }
    
    
    public:
    bool isSpaceoptimization(vector<int> arr, int n )
{
    int sum=0;
    int i, j;
    
    for(i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    
    if(sum%2!=0) return false;
    
    bool part[sum/2+1];
    
    for(i=0;i<=sum/2;i++) part[i]=0;
    
    for(i=0;i<n;i++)
    {
        for(j=sum/2;j>=arr[i];j--)
        {
            if(part[j-arr[i]]==1||j-arr[i])
            part[j]=1;
        }
    }
    return part[sum/2];
}    
};
int main()
{
    vector<int> arr={3, 1, 1, 2, 2, 1 };
   // int target= 9;
    Sol s;
    if(s.isSpaceoptimization(arr, 6)==true)
{
    cout<<"trturn true"<<endl;
}    
    
}
