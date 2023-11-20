#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];

    }
    for(int i=n-1;i>=0;i--)
    {
    for(int j=i+1;j<n;j++)
    {
       if(arr[i]==arr[j])
       {
        continue;
       }
       else if(arr[i]>arr[j])
       {
        int mun=arr[i]-arr[j];
        arr[i]=arr[i]-mun;
        arr[j]=arr[j]+mun;
       }

}


}
for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";

    }

}