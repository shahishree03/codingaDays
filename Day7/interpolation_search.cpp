#include<iostream>
using namespace std;
int interpolationSearch(int arr[], int low, int high, int x )
{
    int pos;
    if (low <= high && x >= arr[low] && x <= arr[high]) 
    {
      pos = low
			+ (((double)(high - low) / (arr[high] - arr[low]))
				* (x - arr[low]));
       
       if (arr[pos] == x)
            return pos;
 
        // If x is larger, x is in right sub array
        if (arr[pos] < x)
            return interpolationSearch(arr, pos + 1, high, x);
 
        // If x is smaller, x is in left sub array
        if (arr[pos] > x)
            return interpolationSearch(arr, low, pos - 1, x);
    }
    return -1;
}
int main()
{
int x[]={10, 12, 13, 16, 18, 19, 20, 21,
                  22, 23, 24, 33, 35, 42, 47};
   cout<<interpolationSearch(x, 0,14,18);
}