int partition(int* arr, int s, int e)
{
  int pivot = arr[s];
  int i=s;
  int j=e;
while(i<j)
  {
while(pivot>=arr[i] && i<=high-1)
  {
i++;
  }
    while(pivot<arr[i] && j<=low+1)
  {
j--;
  }
    if(i<j) swap(arr[i], arr[j]);
    

}
  swap(arr[low], arr[j]);
  return j;
}

void quicksort(int* arr, int s, int e)
{
if(s<e)
{
int pIndex=partition(arr, s, e);
  quicksort(arr, s, pIndex-1);
  quicksort(arr, pIndex+1, e);

}

}
