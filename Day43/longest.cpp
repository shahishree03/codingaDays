#include<iostream>
#include<vector>
using namespace std;
int num_Arr(vector<int>& arr, int n, int k)
{
    int left=0;
    int right = 0;
    long long sum =arr[0];
    int maxlen =0;
    while(right<n)
    {
        while(left<=right && sum>k)
        {
            sum-=arr[left];
            left++;
        }
        if(sum==k)
        {
            maxlen = max(maxlen, right-left+1);
        }
        right++;
        if(right<n) sum+=arr[right];
        
    }
    return maxlen;
}
int main()
{
    vector<int> arr={2, 3, 5, 1, 9};
    long long k = 10;
    int len = num_Arr(arr,5, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}
