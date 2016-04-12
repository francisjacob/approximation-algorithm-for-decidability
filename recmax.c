
//max
void MAXX(A,left,right)
{
    if (left == right - 1)
      return A[left]
      else
      {
        max1= MAXX(A,left,right/2);
        max2= MAXX(A,right/2,right);
      }
      if (max1 > max2)
         return max1
      else
         return max2
}

