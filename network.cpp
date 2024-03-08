#include<bits/stdc++.h>
using namespace std;
bool checkPoweroftwo(int n)
{
    if(n<=0)  return 0;
    if(n&(~(n-1))==n) return 1;
    else{
        return 0;
    }
    
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
   int maxVal =INT_MIN;
    for(int i=0;i<n-1;i++)
    {
      if(checkPoweroftwo(arr[i]))
      maxVal=max(maxVal, arr[i]);
      
      else
      {
        int two =arr[i]-pow(2, floor(log2(arr[i])));
        arr[i+1]=arr[i+1]+two;
        cout<<"Arr[i]"<<arr[i]<<" "<<endl;
        arr[i]=pow(2, floor(log2(arr[i])));
      //  cout<<" two: "<<two<<endl;
       
        maxVal=max(maxVal,arr[i]);
         cout<<"maxVal: "<<maxVal<<" "<<endl;
        
      }
    }
    cout<<maxVal;
}
