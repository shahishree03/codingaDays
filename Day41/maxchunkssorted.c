int maxChunksToSorted(int* arr, int arrSize) {
    int sum_i=0, sum_ar=0, ans=0;
    for(int i=0;i<arrSize;i++)
    {
        sum_i+=i;
        sum_ar+=arr[i];
        if(sum_i==sum_ar)
        ans++;
    }
    return ans;
}
