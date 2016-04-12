void convexHull(points[],n)
{
    // There must be at least 3 points
    if (n < 3) return;

    // Initialize Result
    vector<Point> hull;

    // Find the leftmost point
    int l = 0;
    for(int i = 1;i<n;i++)
        if (points[i].x < points[l].x)
            l = i;

    // Start from leftmost point, keep moving counterclockwise
    // until reach the start point again.  This loop runs O(h)
    // times where h is number of points in result or output.
    int p = l, q;
    while(p>1)
    {
        p++;

        hull.push_back(points[p]);


        q = (p+1)%n;
        for(int i = 0;i<n;i++)
        {

           if (orientation(points[p], points[i], points[q]) == 2)
               q = i;
        }


        p = q;

    }

    // Print Result
    for(int i = 0;i<hull.size();i++)
        cout << "(" << hull[i].x << ", "
              << hull[i].y << ")\n";
}
