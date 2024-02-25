if (n <= 1) {
        return {1,0};
    }
 
    // Initialize boundaries for binary search
    double res1 = exp(log(n)/2);
    int res = round(res1);
    if(res*res==n)
    return {n,0};
    else
    {
        return {res*res, abs(res*res-n)};
    }
