#include<iostream>
#include<vector>
using namespace std;
int main()
{
 vector<int> arr={1,3,3,9,10, 4};
  int range11=1, range12=4;
  int range21=9, range22 = 12;
  int count1=0, count2=0;
  for(int i=0;i<6;i++)
    {
     if(arr[i]>=range11 && range12>=arr[i]) 
     {
       count1++;
    }
      if(arr[i]>=range21 && range22>=arr[i])
      {
count2++;
      }
      
      
}
cout<<"Range1: "<<count1<<" Range2: "<<count2<<endl;
  
}
