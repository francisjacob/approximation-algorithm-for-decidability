void isPolynomialrec(struct RE x)
{
    printf("%dT(n%c%c)\n",x.a,x.c,x.b);
    switch(x.c)
    {
        case '/': if(x.d==1)
                        printf("O(nlogn + c1)");
                  else if(x.d==0)
                        printf("O(logn + c1)");
                  printf("\n\nThe given input code can be run in polynomial time(P)\n\n");
                  break;
        case '%': if(x.d==1)
                        printf("O(nlogn + c1)");
                  else if(x.d==0)
                        printf("O(logn + c1)");
                  printf("\n\nThe given input code can be run in polynomial time(P)\n\n");
                  break;
        case '+': printf("O(n!)");
                  printf("\n\nThe given input code is a non-polynomial time algorithm(NP)\n\n");
                  break;
        case '-': printf("O(2^n)");
                  printf("\n\nThe given input code is a non-polynomial time algorithm(NP)\n\n");
                  break;
    }
}

void isPolynomialnonrec(int x)
{
    switch(x)
    {
        case 0:printf("O(n)");
                break;
        case 1:printf("O(logn)");
                break;
        case 2:printf("O(loglogn)");
                break;
        case 3:printf("O(nlogn)");
                break;
        case 4:printf("O(n^2)");
                break;
        case 5:printf("O(nloglogN)");
                break;
        case 6:printf("O(n^3)");
                break;
        case 7:printf("O(n^2logn)");
                break;
        case 8:printf("O(n^2 loglogn)");
                break;
        default: printf("O(1)");
                break;
    }
    printf("\n\nThe given input code can be run in polynomial time(P)\n\n");
}
