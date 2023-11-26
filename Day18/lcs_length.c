#include <stdio.h>
#include <limits.h>

void printParenthesis( int bracket[], char* X, int i ,int j) {
    // If only one matrix left in the current segment
    if (i == j) {
        return;
    }
 if(b[i][j]=='^'){
    printParenthesis(bracket, X, i-1 , j-1);
    printf("%d",X[i]);
 }
    
    else if(b[i][j]=='^'){
    printParenthesis(bracket, X, i-1 , j);
    }
    else{
         printParenthesis(bracket, X,i , j-1);
    }
    // Recursively put brackets around subexpression
    // from bracket[i][j] + 1 to j.
    printParenthesis(bracket[i][j] + 1, j, n, bracket, name);
    printf(")");
}
void LCSLength(char* X, char* Y, int m , int n)
{
  int b[m][n], c[m+1][n+1];
  for(int i=1;i<=m;i++)
  {
    c[i][0] =0;
  }
  for(int j=0;j<=n;j++)
  {
    c[0][j] =0;
  }
for(int i=1;i<=m;i++)
  {
    for(int j=1;j<=n;j++)
  {
    if(X[i] == Y[j])
     {
        c[i][j] = c[i-1][j-1]+1;
       b[i][j] ='^';
     }
     else if(c[i-1][j] >= c[i][j-1])
     {
        c[i][j] =c[i-1][j];
        b[i][j] = '|';
        
     }
     else
  {
    c[i][j] =c[i][j-1];
        b[i][j] = '-';
  }
  }
  }


  =

    printf("Optimal Parenthesization is : ");
    printParenthesis(1, n - 1, n, bracket, &name);
    printf("\nOptimal Cost is : %d\n", c[1][n - 1]);
  
}
int main()
{
    char *X
char *Y;
printf("Input of Text: ");
scanf("%s", X);
printf("Input of Pattern: ");
scanf("%s",Y);
printf("Text: %s\n", X);
printf("Pattern: %s\n", Y);
int m =X.length();
int n = Y.length();
    
}