int trap(int* height, int heightSize) {
    int l =0;
    int r = heightSize-1;
    int maxleft=0, maxright =0;
    int res=0;
    while(l<=r)
    {
     if(height[l]<=height[r])
     {
     if(height[l]>=maxleft)
     {
        maxleft= height[l];

     }
     else{
        res+=maxleft-height[l];
     }
l++;
     }
     else
     {
       if(height[r]>=maxright)
       {
        maxright = height[r];
       }
       else{
        res+= maxright - height[r];
       }
       r--;
     }
     }
     return res;
    }
