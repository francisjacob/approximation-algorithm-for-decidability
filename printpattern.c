void printPattern(flag,n,m)
{
    // Print m.
    cout << m << " ";

    // If we are moving back toward the n and
    // we have reached there, then we are done
    if (flag == false && n ==m)
        return;

    // If we are moving toward 0 or negative.
    if (flag)
    {
      // If m is greater, then 5, recur with true flag
      if (m-5 > 0)
         printPattern(true,n, m-5);
      else // recur with false flag
         printPattern(false,n, m-5);
    }

}
