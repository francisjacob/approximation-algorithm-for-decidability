
void displayRE(struct RE);
struct RE findRecurrenceEquation(FILE *filePtr);
struct RE RecursiveTC(FILE *filePtr)
{
    char c;
    int flag=1;

    while( (c=fgetc(filePtr)) != EOF)
    {
        if(c == 'i' || c == 'f' || c == 'v' || c=='b')
        {
            char *str1=(char*)malloc(5*sizeof(char));
            int n=0;
            switch(c)
            {
            case 'i':{
                    str1[n++]=c;
                    while(isalpha((c=fgetc(filePtr))))
                    {
                        str1[n++]=c;
                    }
                    str1[n]='\0';
                    if((strcmp(str1,"int"))==0)
                        flag=0;
                    break;
                    }
            case 'f':{
                    str1[n++]=c;
                    while(isalpha((c=fgetc(filePtr))))
                    {
                        str1[n++]=c;
                    }
                    str1[n]='\0';
                    if((strcmp(str1,"float"))==0)
                        flag=0;
                    break;
                }
            case 'v':{
                    str1[n++]=c;
                    while(isalpha((c=fgetc(filePtr))))
                    {
                        str1[n++]=c;
                    }
                    str1[n]='\0';
                    if((strcmp(str1,"void"))==0)
                        flag=0;
                    break;
                    }
            case 'b':{
                        str1[n++]=c;
                        while(isalpha((c=fgetc(filePtr))))
                        {
                            str1[n++]=c;
                        }
                        str1[n]='\0';
                        if((strcmp(str1,"bool"))==0)
                            flag=0;
                        break;
                    }
            }
        }
        if(flag==0)
        {
            c=fgetc(filePtr);
            int n=0;
            char str[100];
            if(isalpha(c))
            {

                str[n++]=c;
                while(isalpha(c=fgetc(filePtr)))
                    str[n++]=c;
                str[n]='\0';
            }

            // if the input read is a function.
            if(strcmp(str,functionname[0])==0)
            {
                struct RE re;
                re=findRecurrenceEquation(filePtr);
                return re;
            }

        }
    }
}

//function to find recurrence equation
struct RE findRecurrenceEquation(FILE *filePtr)
{
    struct RE x;
    x.d=0;
    int counter=0;
    char c;
    int n=0;

    while((c=fgetc(filePtr))!='{');
    n++;
    while(n>0)
    {
        c=fgetc(filePtr);
        if(c== '{')
        {
            n++;
            continue;
        }
        if(c == '}')
        {
            n--;
            continue;
        }
        else if(isalpha(c))
        {
            char str[100];
            int num=0;
            str[num++]=c;
            while(isalpha(c=fgetc(filePtr)))
                str[num++]=c;
            str[num]='\0';
            char var;
            int len=strlen(functionname[0]);
            char strtmp[len];
            int f;
            for(f=0;f<len/2;f++)
                strtmp[f]=functionname[0][f];
            strtmp[f]='\0';

            if(strcmp(str,functionname[0])==0)
            {
                counter++;
                fseek(filePtr, -1, SEEK_CUR);
                while((c=fgetc(filePtr))!=';')
                {
                    char str1[100];
                    int num1=0;
                    fseek(filePtr, -1, SEEK_CUR);
                    while(isalpha(c=fgetc(filePtr)))
                        str1[num1++]=c;
                    str1[num1]='\0';
                    if(strcmp(str1,functionname[fnumber])==0)
                    {
                        var=c;
                        if(var == '/' || var == '%')
                        {
                            x.c=var;
                            c=fgetc(filePtr);
                            x.b= c ;


                        }
                        else if(var == '+')
                        {
                            x.c=var;
                            c=fgetc(filePtr);
                            x.b= c ;

                        }
                        else if(var == '-')
                        {
                            x.c=var;
                            c=fgetc(filePtr);
                            x.b= c ;

                        }
                        else if(var == '*')
                        {
                            x.c=var;
                            c=fgetc(filePtr);
                            x.b= c ;

                        }
                        else if(var == ',')
                        {
                            x.c='\0';
                            x.b='\0';

                        }
                    }
                }
            }
            else if(strcmp(str,strtmp)==0)
            {

                x.d=1;
            }
        }
    }
    x.a=counter;
    return x;
}


