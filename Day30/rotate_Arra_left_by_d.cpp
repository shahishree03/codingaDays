#include<iostream>
#include<vector>
using namespace std;
int gcd(int a, int b)
{
if(b==0) return a;
  return gcd(b,a%b);
}

void rotation(vector<int>& arr, int d ,int n)
{
d=d%n;
  int gc =gcd(d, n);
  for(int i=0;i<n;i++)
    {
      int temp=arr[i];
      int j=i;
 while(1)
   {
   int k=j+d;
     if(k>=n) k=-n;
     if(k==i) break;
     arr[j]=arr[k];
     j=k;

   }

      arr[j]=temp;
    }

}

void printAr(vector<int>& arr, int n)
{
for(int i=0;i<n;i++)
  {
cout<<arr[i]<<" ";
  }
}
int main()
{
vector<int>arr ={1,2,3,4,5,6,7};
  leftrotation(arr, arr.size());
  printAr(arr, arr.size());

}
