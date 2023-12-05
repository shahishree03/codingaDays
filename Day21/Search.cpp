#include<iostream>
#include<algorithm>

using namespace std;
class Search{

public:
  
    int binarysearch(int* arr, int start, int high ,  int key)
    {
        if(high<=start){
       int mid=start+(high-start)/2;
       if(arr[mid]==key)
       {
         return mid;
       }
       if(arr[mid]<key)
        return binarysearch(arr, start, mid-1, key);

        else  return binarysearch(arr, mid+1, high, key);
      }

      return -1;
    }

    int exponentialsearch(int* arr , int n , int x)
    {
        if(arr[0]==x)
       return 0;

        int i=1;
        while(i<n && arr[i]<=x)
           i=i*2;
        
        
        return binarysearch(arr, i/2, min(i,n-1), x);
    }

};
int main()
{
int arr[]={10, 2, 7, 5, 8};
Search s;


int k = s.exponentialsearch(arr, 10, 5);
cout<<"\n\n";
 cout<<k<<endl;

}