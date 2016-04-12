//fail case. answer is O(n)
void rvereseArray(arr[],start,end)
{
   int temp;
   if (start >= end)
     return;
   temp = arr[start];
   arr[start] = arr[end];
   arr[end] = temp;
   rvereseArray(arr, start+1, end-1);
}
