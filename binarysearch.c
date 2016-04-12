void binarysearch(A[],a,l,h)
{
    if(A[h/2]==a)
        return 1;
    else if(a<A[h/2])
        binarysearch(A,a,l,h/2);
    else
        binarysearch(A,a,h/2,l);
}
