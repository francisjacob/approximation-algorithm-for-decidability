

int checkloopf(char c,FILE *filePtr);
int checkloopw(char c,FILE *filePtr);
int OP(char c);
int nonRecursiveTC(FILE *filePtr)
{
    loopstack.head=0;
    enum timeccomplexity tc;
    int flag=0,flag1=0;
    char c;
    while((c=fgetc(filePtr))!= EOF)
    {
        char str[100];
        int n=0;
        // check for 'for' loop.
        if(c=='f')
        {

            if(checkloopf(c,filePtr))
            {
                n=0;
                flag=1;
                int lesser;
                while((c=fgetc(filePtr))!=';');
                while((c=fgetc(filePtr)))
                {
                    if(c=='<')
                    {
                        lesser=1;
                        break;
                    }
                    else if(c=='>')
                    {
                        lesser=0;
                        break;
                    }
                    else if(c == ';')
                        break;
                }
                if(lesser==1)
                {
                    while((c=fgetc(filePtr))!=';')
                    {
                        if(c!=' ')
                            str[n++]=c;
                    }
                }
                else
                {
                    c=fgetc(filePtr);
                }
                str[n]='\0';
                if(((strcmp(str,functionname[fnumber])==0)&&lesser==1)||(lesser==0&&(c=='0' || c=='1')))
                {
                    while((c=fgetc(filePtr))!=')')
                    {
                        int op;
                        if((op=OP(c)))
                        {
                            if(loopstack.head<1)
                            {
                                switch(op)
                                {
                                    case 1:
                                            tc=On;//printf("O(n)");
                                            break;
                                    case 2:tc=Ologn;//printf("O(log n)");
                                            break;
                                    case 3:tc=Ologlogn;//printf("O(log log n)");
                                            break;
                                    default: printf("undefined");
                                            break;
                                }
                            }
                            else if(loopstack.head == 1)
                            {
                                switch(op)
                                {
                                    case 1:
                                            if(tc==On)
                                                tc=On2;
                                            else if(tc==Ologn)
                                                tc=Onlogn;

                                            break;
                                    case 2:
                                            if(tc==On)
                                                tc=Onlogn;

                                            break;
                                    case 3:
                                            if(tc==On)
                                                tc=Onloglogn;

                                                break;
                                }
                            }
                             else if(loopstack.head>1)
                            {
                                  switch(op)
                                {
                                    case 1:
                                            if(tc==On2)
                                                tc=On3;
                                            else if(tc==Onlogn)
                                                tc=On2logn;
                                            break;
                                    case 2:
                                            if(tc==On2)
                                                tc=On2logn;
                                            break;
                                    case 3:
                                            if(tc==On2)
                                                tc=On2loglogn;
                                                break;
                                }
                            }
                        }

                    }
                }
            }
        }
        else if(c=='w') //check for while loop
        {
            int lesser;
            if(checkloopw(c,filePtr))
            {
                while((c=fgetc(filePtr)))
                {
                    if(c=='<')
                    {
                        lesser=1;
                        break;
                    }
                    else if(c=='>')
                    {
                        lesser=0;
                        break;
                    }
                    else if(c==')')
                    {
                        lesser=-1;
                        break;
                    }
                }
                if(lesser==1)
                {
                    while(isalpha(c=fgetc(filePtr)))
                    {
                        str[n++]=c;
                    }
                }
                else
                {
                    c=fgetc(filePtr);
                }
                str[n]='\0';

                if(((strcmp(str,functionname[fnumber])==0)&&lesser==1)||(lesser==0&&(c=='0' || c=='1')))
                {
                    //assumption is made that increment happens in the first line

                    char g='{';
                    s_push(g);
                    while((c=fgetc(filePtr))!=';')
                    {
                        int op;
                        if((op=OP(c)))
                        {
                            if(loopstack.head<2)
                            {
                                switch(op)
                                {
                                    case 1: tc=On;//printf("O(n)");
                                            break;
                                    case 2:tc=Ologn;//printf("O(log n)");
                                            break;
                                    case 3:tc=Ologlogn;//printf("O(log log n)");
                                            break;
                                    default: printf("Undefined");
                                            break;
                                }
                            }
                            else if(loopstack.head<3)
                            {
                                switch(op)
                                {
                                    case 1:if(tc==On)
                                                tc=On2;
                                            else if(tc==Ologn)
                                                tc=Onlogn;
                                            break;
                                    case 2:if(tc==On)
                                                tc=Onlogn;
                                            break;
                                    case 3:if(tc==On)
                                                tc=Onloglogn;
                                                break;
                                }
                            }
                            else
                            {
                                switch(op)
                                {
                                    case 1:if(tc==On2)
                                                tc=On3;
                                            else if(tc==Onlogn)
                                                tc=On2logn;
                                            break;
                                    case 2:if(tc==On2)
                                                tc=On2logn;
                                            break;
                                    case 3:if(tc==On2)
                                                tc=On2loglogn;
                                                break;
                                }
                            }
                        }
                    }
                }
            }
        }
        if(c=='{' && flag==1)
           s_push(c);
        if(c=='}' && flag==1)
        {
            s_pop();
        }

    }
    rewind(filePtr);
    while((c=fgetc(filePtr))!=EOF)
    {
        char str[100];
        int n=0;
        if(c=='q')
        {
            str[n++]=c;
            while(isalpha(c=fgetc(filePtr)))
                str[n++]=c;
            str[n]='\0';
            if(strcmp(str,"qsort")==0)
            {
                if(tc<Onlogn)
                    tc=Onlogn;
            }
        }
    }

    return tc;
}

int checkloopf(char c,FILE *filePtr)
{
    char *str=(char*)malloc(3*sizeof(char));
    int num=0;
    str[num++]=c;
    while(isalpha((c=fgetc(filePtr))))
    {
        str[num++]=c;
    }
    str[num]='\0';
    if(strcmp(str,"for")==0)
        return 1;
    else
        return 0;
}
int checkloopw(char c,FILE *filePtr)
{
    char *str=(char*)malloc(5*sizeof(char));
    int num=0;
    str[num++]=c;
    while(isalpha((c=fgetc(filePtr))))
    {
        str[num++]=c;
    }
    str[num]='\0';
    if(strcmp(str,"while")==0)
        return 1;
    else
        return 0;
}
int OP(char c)
{
    if(c=='+' || c=='-')
        return 1;
    else if(c=='*' || c=='/')
        return 2;
    else if(c=='^')
        return 3;
    else
        return 0;
}
