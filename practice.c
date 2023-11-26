#include<stdio.h>

void display_PointerIncr(int* arr)
{
    for(int i=0;i<5;i++)
    {
      printf("%d\n", *(arr+i));
    }
}
void find_duplicate(int* arr)
{
    for(int i=0;i<4;i++)
    {
     for(int j=i+1;j<5;j++)
    {
      if(arr[i]==arr[j])
      {
        printf("The %d duplicate element is at %d and %d \n", arr[i], i , j);
      }
    }
    }
}
int main()
{
    int arr[5];
    printf("Provide 5 elements for array\n");
    for(int i=0;i<5;i++)
    {
        scanf("%d", &arr[i]);
    }
   printf("Displaying Elements\n");
   display_PointerIncr(arr);
   find_duplicate(arr);




}




