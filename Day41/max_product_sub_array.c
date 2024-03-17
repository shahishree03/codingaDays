#include<math.h>
int maxProduct(int* nums, int numsSize) {
   int prefix=1;
   int suffix=1;
   int ans=INT_MIN;
   for(int i=0;i<numsSize;i++)
   {
    prefix=(prefix==0?1:prefix);
    suffix=(suffix==0?1:suffix);
    prefix =prefix*nums[i];
    suffix=suffix*nums[numsSize-i-1];
ans=fmax(ans, fmax(prefix, suffix));

   }
   return ans;
}
