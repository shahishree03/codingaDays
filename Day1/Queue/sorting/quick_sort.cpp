#include<iostream>
using namespace std;
void swap(int*a , int* b)
{
    int temp = *a;
    *a=*b;
    *b = temp;
}
int partition(int* arr, int left , int right)
{
   int pivot = arr[left];
int i = left;
int j=right;
while(i<j)
{
    while(pivot >=arr[i] && i<=right-1)
    {
        i++;
    }
    while(pivot<arr[j] && j>= left+1)
    {
        j--;
    }
    if(i<j) swap(&arr[i++], &arr[j--]);
}
swap(&arr[left], &arr[j]);
return j;
}
int partition_1(int* arr, int left , int right)
{
  int pivot = arr[right];
    int i = left - 1;
    
    for (int j = left; j <= right - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[right]);
    return i + 1;
}
void quickSort(int* arr, int left, int right)
{
    if(left<right)
    {
        int pivotIndex= partition(arr, left, right);
        quickSort(arr, left, pivotIndex-1);
        quickSort(arr, pivotIndex+1, right);
    }
}


int main()
{
    int n =8;
    int arr[10]={4, 6, 2, 5, 7, 9, 1, 3};
        
        cout << "Before Using quick Sort: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    quickSort(arr, 0, 7);
    cout << "After Using quick sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}