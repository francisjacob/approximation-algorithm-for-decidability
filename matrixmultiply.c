int matrixmultiply(A[][],B[][],n)
{
    int i,j,k;
    int c[][];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
            {
                c[i][j]=a[i][k]+b[k][j];
            }
        }
    }

}
