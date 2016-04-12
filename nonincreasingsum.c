//fail case
void generateUtil(int x, int arr[],currsum,curridx)
{
   // If current sum is equal to x, then we found a sequence
   if (curr_sum == x)
   {
      printArr(arr, curr_idx);
      return;
   }

   // Try placing all numbers from 1 to x-curr_sum at current index
   int num = 1;

   // The placed number must also be smaller than previously placed
   // numbers, i.e., arr[curr_idx-1] if there exists a pevious number
   while (num<=x-currsum && (curridx==0 || num<=arr[curridx-1]))
   {
       // Place number at curr_idx
       arr[curr_idx] = num;

       // Recur
       generateUtil(x, arr, currsum+num, curridx+1);

       // Try next number
       num++;
   }
}
