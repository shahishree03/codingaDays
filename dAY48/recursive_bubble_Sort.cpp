if(n==1) return;
      for(int i=0;i<=n-2;i++)
      {
          if(arr[i]>arr[i+1])
          swap(arr[i], arr[j]);
      }
      bubbleSort(arr, n-1);
    }
