//fail test

void subsetsum(s[],t[],s_size,t_size,ite,target_sum,sum)
{
    total_nodes++;
    if( target_sum == sum )
    {
        // We found subset
        printSubset(t, t_size);
        // Exclude previously added item and consider next candidate
        subsetsum(s,t,s_size,t_size-1,ite+1,target_sum,sum-s[ite]);
        return;
    }
    else
    {
        // generate nodes along the breadth
        for( int i = ite; i < s_size; i++ )
        {
            t[t_size] = s[i];
            // consider next level node (along depth)
            subsetsum(s,t,s_size,t_size + 1,i + 1,target_sum,sum+s[i]);
        }
    }
}
