int longestevensubstring(str[][],n)
{
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
            {
                leftsum  += (str[i+k]-'0');
                rightsum += (str[i+k+length/2]-'0');
            }
             if (leftsum == rightsum && maxlen < length)
                    maxlen = length;
        }
    }
      return maxlen;
}
