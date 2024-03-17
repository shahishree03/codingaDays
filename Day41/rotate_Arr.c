#include<stdio.h>
#include<stdlib.h>
void rotate(int* nums, int k, int n)
{
  k=k%n;
int temp[n];
  for(int i=0;i<n;i++)
    temp[(i+k)%n]= nums[i];
for(int i=0;i<n;i++)
  {
nums[i]=temp[i];
  }
}
int main()
{
  int n;
  scanf("%d", &n);
  int arr[n];
  for(int i=0;i<n;i++){
scanf("%d", &arr[i]);
  }
  
rotate(arr,3 , n);

for(int i=0;i<n;i++){
printf("%d  ", arr[i]);
  }
}
