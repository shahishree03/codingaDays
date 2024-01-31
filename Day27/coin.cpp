/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>

using namespace std;
/*target sum = */
//naiva approach

int minimum_coins(int target, vector<int>&coins)
{
 int ans;
if (target==0) ans=0;
for (int i=0;i<coins.size();i++)
  {
   int subproblem = target-coins[i];
    if(subproblem<0){
      continue;
    }
ans =min(ans, minimum_coins(subproblem, coins)+1);
    
  }

  return ans;
  
}
int main()
{
    vector<int> a={1,4,5};
    cout<<minimum_coins(13, a);

    return 0;
}
