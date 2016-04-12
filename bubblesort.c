void bubbleSort(arr[],n)
{
   int i, j;
   for (i = 0; i < n; i++)
    {
       // Last i elements are already in place
       for (j = 0; j < n ; j++)
       {
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
       }
    }
}
