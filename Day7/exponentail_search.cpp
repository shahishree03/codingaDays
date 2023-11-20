#include<iostream>
using namespace std;

int binarysearch(int* arr, int low, int high , int x)
{
    if(low<=high)
    {
        int mid = low+(high-low)/2;

        if(arr[mid]==x) return mid;
        if(arr[mid]>x) return binarysearch(arr, low, mid-1, x);
        if(arr[mid]<x) return binarysearch(arr, mid+1, high, x);
    }
return -1;

}
int exponentsearch(int* arr, int n , int x)
{
    if(arr[0]==x)
    return 0;

    int i=1;
    while(i<n && arr[i]<=x)
    {
        i*=2;
    }
    return binarysearch(arr, i/2, min(i, n-1), x);
}

int main()
{
     int arr[] = {2, 3, 4, 10, 40};
   int n = sizeof(arr)/ sizeof(arr[0]);
   int x = 10;
   int result = exponentsearch(arr, n, x);
   (result == -1)? cout <<"Element is not present in array"
                 : cout <<"Element is present at index " << result;
   return 0;
}