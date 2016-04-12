#include<stdio.h>
#include<stdlib.h>
#include<string.h>



/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs(*X,*Y,m,n)
{
   if (m == 0 || n == 0)
     return 0;
   if (X[m-1] == Y[n-1])
     return 1 + lcs(X,Y,m-1,n-1);
   else
     return max(lcs(X,Y,m-1,n),lcs(X,Y,m,n-1));
}

/* Utility function to get max of 2 integers */
int max(int a, int b)
{
    return (a > b)? a : b;
}

/* Driver program to test above function */
int main()
{
  char X[] = "AGGTAB";
  char Y[] = "GXTXAYB";

  int m = strlen(X);
  int n = strlen(Y);

  printf("Length of LCS is %d\n", lcs( X, Y, m, n ) );

  return 0;
}