#include<stdio.h>
#include<limits.h>
void printParenthesis(int i , int j , int n , int bracket[][n], char* name)
{
    if (i == j) {
        printf("%c", (*name)++);
        return;
    }

    printf("(");

    // Recursively put brackets around subexpression
    // from i to bracket[i][j].
    printParenthesis(i, bracket[i][j], n, bracket, name);

    // Recursively put brackets around subexpression
    // from bracket[i][j] + 1 to j.
    printParenthesis(bracket[i][j] + 1, j, n, bracket, name);
    printf(")");
}
int matrixchainorder(int p[], int n)
{
    int m[n][n];
    int bracket[n][n];
    int k;
    for(int i=1;i<n;i++)
    {
        m[i][i]=0;
    }
    
    int j;
    for(int L=2;L<n;L++)
    {
        for(int i=1;i<n-L+1;i++)
        {
            j=i+L-1;
            m[i][j]=INT_MAX;
            for(k=i;k<j;k++)
            {
                int q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(q<m[i][j])
                {
                    m[i][j]= q;
                    bracket[i][j]=k;
                }
            }
        }
    }
    
    char name = 'A';

    printf("Optimal Parenthesization is : ");
    printParenthesis(1, n - 1, n, bracket, &name);
    printf("\nOptimal Cost is : %d\n", m[1][n - 1]);
}
int main()
{
     int arr[] = { 1, 2, 3, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    matrixchainorder(arr, n);
    return 0;
}
