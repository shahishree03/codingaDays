#include<stdio.h>

int max(int a, int b) { return (a > b) ? a : b; } 
int zero_one_Knapsack(int W, int w[], int val[], int n)
{
    if(n==0||W==0)
    return 0;
    
    if(w[n-1]>W)
     return zero_one_Knapsack(W, w,val, n-1);
     
    else
    {
        return max(val[n-1]+zero_one_Knapsack(W-w[n-1], w, val, n-1), zero_one_Knapsack(W, w, val, n-1));
    }
}
int main()
{
     int profit[] = { 60, 100, 120 }; 
    int weight[] = { 10, 20, 30 }; 
    int W = 50; 
    int n = sizeof(profit) / sizeof(profit[0]); 
    printf("%d", zero_one_Knapsack(W, weight, profit, n)); 
    return 0; 
    
}
