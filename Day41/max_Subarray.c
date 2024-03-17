#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>
int alternative_sum(int* arr, int n)
{

int max_so_far=0;
int sum=0, start =0, end=0, s=0;
  for(int i=0;i<n;i++)
    {
    sum+=arr[i];
      if(max_so_far<sum)
      {
max_so_far=sum;
        start=s;
        end=i;
      }
if(sum<0)
{
sum=0;
  s=i+1;
}
      
      
    }
  return max_so_far;
}


int main()
{
    int a[]={-2, -3, 4, -1, -2, 1, 5, -3};
   int arr[8];
   for(int i=0;i<8;i++)
   {
       arr[i]=0;
   }
   arr[0]=a[0];
   int ans=arr[0];
   for(int i=1;i<8;i++)
   {
       arr[i]= fmax(arr[i], arr[i-1]+a[i]);
       ans = fmax(ans, arr[i]);
   }
   
   printf("%d", ans);
}
