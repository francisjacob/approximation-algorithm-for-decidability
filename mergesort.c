


int mergeSort(arr[],l,r)
{
    if (l < r)
    {

        mergeSort(arr,l, r/2);
        mergeSort(arr,r/2,r);
        merg(arr, l, m, r);
    }
}

void merge(int arr[],int arr1[], int l, int m, int r)
{
    int i,j,k;
    int n1=m-l+1;
    int n2=r-m;
    int L[n1],R[n2],L1[n1],R1[n2];
    for(i=0;i<n1;i++)
    {
        L[i]=arr[l+i];
        L1[i]=arr1[l+i];
    }
    for(j=0;j<n2;j++)
    {
        R[j]=arr[m+1+j];
        R1[j]=arr1[m+1+j];
    }
    i=j=0;
    k=l;
    while(i<n1 && j<n2)
    {
        if(L[i]<R[j])
        {
            arr[k]=L[i];
            arr1[k]=L1[i];
            k++;
            i++;
        }
        else
        {
            arr[k]=R[j];
            arr1[k]=R1[j];
            k++;
            j++;
        }
    }
    while(i<n1)
    {
        arr[k]=L[i];
        arr1[k]=L1[i];
        k++;
        i++;
    }
    while(j<n2)
    {
        arr[k]=R[j];
         arr1[k]=R1[j];
        k++;
        j++;
    }
}


void printArray(int A[],int a1[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d  %d \n", A[i],a1[i]);
    printf("\n");
}

int main()
{
    int arr[] = {35, 48, 33, 26, 16, 11, 14, 37, 41, 12, 47, 38, 23, 4, 0, 10, 47, 30, 46, 38, 26};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    int arr1[]={51, 53, 40, 54, 23, 39, 33, 70, 61, 45, 78, 77, 50, 12, 4, 25, 77, 35, 53, 38, 61 };

    mergeSort(arr,arr1, 0, arr_size - 1);

    printf("\nSorted array is \n");
       printArray(arr,arr1, arr_size);
    return 0;
}

