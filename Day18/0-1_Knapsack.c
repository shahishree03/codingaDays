#include<stdio.h>

int max(int a, int b) { return (a > b) ? a : b; } 
int zero_one_Knapsack(int W, int wt[], int val[], int n)
{
    int i,j;
    int K[n+1][W+1];
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=W;j++)
        {
            if(i==0||j==0)
              K[i][j]=0;
            else if(wt[i-1]<=j)
              K[i][j]=max(val[i-1]+K[i-1][j-wt[i-1]], K[i-1][j]);
            else
              K[i][j]=  K[i-1][j];
        }
    }
    return K[n][W];
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
