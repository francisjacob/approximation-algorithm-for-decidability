
int checkReccurence(FILE *filePtr);
int isRecursive(FILE *filePtr)
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

                int x=checkReccurence(filePtr);
                if(x==1)
                    printf("Recursive function\n");
                 return x;
            }
        }
    }
}
int checkReccurence(FILE *filePtr)
{
    char c;
    int stack=0;

    while((c=fgetc(filePtr))!='{');
    stack++;
    while(stack>0)
    {
        c=fgetc(filePtr);
        if(c== '{')
        {
            stack++;
            continue;
        }
        if(c == '}')
        {
            stack--;
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
            if(strcmp(str,functionname[0])==0)
                return 1;
        }
    }
    return 0;
}
