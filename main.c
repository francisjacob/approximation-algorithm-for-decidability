/*An approximation algorithm to determine if a given algorithm is polynomial or non-polynomial.
    BY Francis Jacob- 2013103578
       Kale Srikar - 2013103036
       Gautham Selvakumar - 2013103035

	Hello!!!
*/
#include"declarations.h"

void main()
{
    printf("\t P vs NP \n\n");

    // open the input file
    FILE *filePtr;
    {
        if((filePtr=fopen("tester/nqueens.c","r"))==NULL)
        {
            printf("error opening file");
            exit(0);
        }

        fseek(filePtr, 0, SEEK_END);
        if (ftell(filePtr) == 0) {
            printf("File is empty.\n");
            exit(1);
        } else {
            rewind(filePtr);
        }
    }


    // Call upon lexical analyzer.
    lex(filePtr);
    lexdisplay();

    rewind(filePtr);

    //Check if recursive.
    if(isRecursive(filePtr))
    {

        struct RE re;
        rewind(filePtr);
        re=RecursiveTC(filePtr);
        isPolynomialrec(re);

    }
    else
    {
        rewind(filePtr);
        int tc=nonRecursiveTC(filePtr);
        isPolynomialnonrec(tc);
    }

    return;
}
