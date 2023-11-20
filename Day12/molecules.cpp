#include<iostream>

using namespace std;

   int main()
{
    int a,b,c,x,y,z;
    cin>>a>>b>>c;
    x=(a+b-c)/2;
    y=(b+c-a)/2;
    z=(a+c-b)/2;
    if((a+b+c)%2)
    {
        cout<<"Impossible\n";
    }
    else if(x<0 or y<0 or z<0)
    {
        cout<<"Impossible\n";
    }
    else
        cout<<x<<" "<<y<<" "<<z<<endl;

}

