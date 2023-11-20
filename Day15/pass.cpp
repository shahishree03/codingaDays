#include<iostream>
#include<vector>
using namespace std;

int main()
{

    int n, p ,q, i=1;
    cin>>n;
    cin>>p;
int a[101]={0};
for(int i=1;i<=p;i++ )
   {
    int x;
    cin>>x;
      ++a[x];
   }
   cin>>q;
    for(int i=1;i<=q;i++ )
   {
    int x;
    cin>>x;
      ++a[x];
   }

   
  for(int i=1;i<=n;i++)
  {
    
    if(a[i]==0)
    { 
    cout<<"Oh, my keyboard!"<<endl;
    return 0;
    }
  }
  
    cout<<"I become the guy."<<endl;
    return 0;

}