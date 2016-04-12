void quicksort(a[],l,h)
{
    if(l<h)
    {
    quic(a,l,h);
    quicksort(a,l,h/x);
    quicksort(a,h/x,h);
    }
}
