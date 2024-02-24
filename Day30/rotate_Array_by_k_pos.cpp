#include<iostream>
#incldue<vector>
using namespace std;
void rotateArray(vector<int& arr, int n , int k )
{
if(k==0) return;

int temp=arr[n-1];
  for(int i=n-1;i>0;i--)
    {
arr[i]=arr[i-1];
    }
  arr[0]=temp;

}
int main()
{
vector<int> arr={1,2,3,4,5,6,7};
  rotateArray(arr, arr.size());
  for(int i=0;i<arr.size();i++)
{
cout<<arr[i]<<"  "; 
}
