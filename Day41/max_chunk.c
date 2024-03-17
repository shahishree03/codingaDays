int maax(int* arr, int n)
{

int temp[2*n+1];
  for(int i=0;i<2*n+1;++i)
    {
temp[i]=INT_MIN;

    }
int maxlen=0 , sum=0;
  for(int i=0;i<n;++i)
    {
sum+=(nums[i]==0?-1:1);
      if(temp[sum+n]>=-1) maxlen = fmax(max,i- temp[sum+n]);
      else temp[sum+n] =i;

    }
  return maxlen;
}
