enum timeccomplexity{On,Ologn,Ologlogn,Onlogn,On2,Onloglogn,On3,On2logn,On2loglogn};
char functionname[20][80];
int fnumber=0;
struct RE
{
    int a;
    char b;
    char c;
    int d;
};
#define MAX 800
#include<stdio.h>
#include"lexical.c"
#include"isRecursive.c"
#include"loopstack.c"
#include"nonRecursiveTC.c"
#include"RecursiveTC.c"
#include"isPolynomial.c"
