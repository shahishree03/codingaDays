#include <iostream>
#include <string>
using namespace std;
// Function to Reverse the array

int main()
{
  int arr[] = {4, 2, 3, 4};
 int xor1=0, xor2=0;
 for(int i=0;i<3;i++)
 {
     xor2=xor2^arr[i];
     xor1=xor1^(i+1);
     
 }
 xor1=xor1^4;
 xor2=xor1^xor2;
 cout<<xor2;
}
