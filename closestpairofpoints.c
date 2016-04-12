float closest(P[],n)
{
    Point Px[n];
    Point Py[n];
    for(int i=0;i<n;i++)
    {
        Px[i] = P[i];
        Py[i] = P[i];
    }
    qsort(Px, n, sizeof(Point), compareX);
    qsort(Py, n, sizeof(Point), compareY);
    return closestUtil(Px, Py, n);
}
