//fail case . answer is O(y)
int multiply(x,y)
{
   /* 0  multiplied with anything gives 0 */
   if(y == 0)
     return 0;

    /* the case where y is negative */
   if(y < 0 )
     return -multiply(x, -y);

   /* Add x one by one */
   if(y > 0 )
     return (x + multiply(x, y-1));


}

int main()
{
  printf("\n %d", multiply(5, -11));
  getchar();
  return 0;
}
