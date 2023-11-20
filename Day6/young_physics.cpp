#include<iostream>
using namespace std;

int main()
{
    int n, ex=0,ey=0,ez=0;
    cin>>n;
    while(n--)
    {
     int x,y,z;
     cin>>x>>y>>z;
     ex=ex+x;
     ey=ey+y;
     ez=ez+z;
    }
    if(ex!=0 ||ey!=0 || ez!=0)
    {
        cout<<"NO";
    }
    else{
        cout<<"YES";
    }
}