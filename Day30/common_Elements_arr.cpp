#include<bits/stdc++.h>
using namespace std;
class Sol{
public:
vector<int> common_elements(int A[], int B[], int C[], int n1, int n2, int n3)
{
unordered_set<int> setA(A, A+n1);
  unordered_set<int> setB(B, B+n2);
  vector<int> res;

  for(int i=0;i<n3;i++)
    {
if(setA.count(C[i]) && setB.count(C[i])
{
  res.push_back(C[i]);
  setA.erase(C[i]);
  setB.erase(C[i]);
    }
}
  return res;
}
};
