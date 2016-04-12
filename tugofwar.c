void tugofwar(int* arr, int n, bool* currelements, int noofselectedelements,
             bool* soln, int* mindiff, int sum, int currsum,currposition)
{
    // checks whether the it is going out of bound
    if (curr_position == n)
        return;

    // checks that the numbers of elements left are not less than the
    // number of elements required to form the solution
    if ((n/2 - noofselectedelements) > (n - currposition))
        return;

    // consider the cases when current element is not included in the solution
    tugofwar(arr, n, currelements, noofselectedelements,
              soln, min_diff, sum, currsum, currposition+1);

    // add the current element to the solution
    noofselectedelements++;
    currsum = currsum + arr[currposition];
    currelements[currposition] = true;

    // checks if a solution is formed
    if (noofselectedelements == n/2)
    {
        // checks if the solution formed is better than the best solution so far
        if (abs(sum/2 - currsum) < *mindiff)
        {
            *mindiff = abs(sum/2 - currsum);
            for (int i = 0; i<n; i++)
                soln[i] = currelements[i];
        }
    }
    else
    {
        // consider the cases where current element is included in the solution
        tugofwar(arr, n, currelements, noofselectedelements, soln,
                  mindiff, sum, currsum, currposition+1);
    }

    // removes current element before returning to the caller of this function
    currelements[curr_position] = false;
}
