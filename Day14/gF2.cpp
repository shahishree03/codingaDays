#include<iostream>
using namespace std;
void swap(int*a , int* b)
{
    int temp = *a;
    *a = *b;
     *b =temp;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];

    }
    
   for(int i=0;i<n-1;i++)
   {
    for(int j=i+1;j<n;j++)
    {
       if(arr[i]>arr[j])
       {
  swap(&arr[i],&arr[j]);
       }
    }
   }



for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";

    }

}