#include<bits/stdc++.h> 
using namespace std;

int main()
{
   int n,arr[100],x=0;
   cin>>n;
   for(int i=0;i<n;i++)
   {
    cin>>arr[i];
    if(arr[i]==1) {
    x++;
    break;
    }
   }

   if(x==0) cout<<"EASY";
   else cout<<"HARD";
}
