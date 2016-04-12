
//toh
void towerOfHanoi(fromrod,torod,auxrod,n)
{
    if (n == 1)
    {
        printf("\n Move disk 1 from rod %c to rod %c", fromrod, torod);
        return;
    }
    towerOfHanoi(fromrod,auxrod,torod,n-1);
    printf("\n Move disk %d from rod %c to rod %c", n, fromrod, torod);
    towerOfHanoi(auxrod,torod,fromrod,n-1);
}

