void countSort(arr[],Range)
{
    char output[strlen(arr)];

    int count[RANGE + 1], i;
    memset(count, 0, sizeof(count));

     for(i=0;arr[i];i++)
    {
        ++count[arr[i]];
    }
     for (i=0;i<Range;i++)
    {
        count[i] += count[i-1];
    }



    for (i=0;arr[i];i++)
    {
        output[count[arr[i]]-1] = arr[i];
        --count[arr[i]];
    }

    for (i=0;arr[i];i++)
    {
        arr[i] = output[i];
    }
}
