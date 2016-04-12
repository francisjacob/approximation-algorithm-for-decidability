void printPascal(n)
{
  for (int line = 1; line < n; line++)
  {
    int C = 1;  // used to represent C(line, i)
    for (int i = 1; i < n; i++)
    {
      printf("%d ", C);  // The first value in a line is always 1
      C = C * (line - i) / i;
    }
    printf("\n");
  }
}
