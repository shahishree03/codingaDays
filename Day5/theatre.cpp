#include <inttypes.h>
#include<stdio.h>


int main()
{
    int64_t n, m , a, res;
    scanf( "%" SCNd64 ,&n);
    scanf( "%" SCNd64 ,&m);
    scanf( "%" SCNd64 ,&a);
    res= ((n+a-1)/a )*((m + a - 1) / a);
    printf("%" PRId64, res);
    
}