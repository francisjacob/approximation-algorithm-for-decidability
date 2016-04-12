void KruskalMST(struct Graph* graph,V)
{

    struct Edge result[V];
    int e = 0;
    int i = 0;


    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);

    struct subset *subsets =
        (struct subset*) malloc( V * sizeof(struct subset) );

    for (int v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }


    while (e < V )
    {
        e++;
        struct Edge next_edge = graph->edge[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        // If including this edge does't cause cycle, include it
        // in result and increment the index of result for next edge
        if (x != y)
        {
            result[e] = next_edge;
            Union(subsets, x, y);
        }
        // Else discard the next_edge
    }

    return;
}
