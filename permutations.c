void permute(char *a,r,l)
{
   int i;
   if (l == r)
     printf("%s\n", a);
   else
   {
       for (i = l; i <= r; i++)
       {
          swap((a+l), (a+i));
          permute(a,r,l+1);
          swap((a+l), (a+i)); //backtrack
       }
   }
}
