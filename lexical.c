
int isExAcceptableChar(char c);
int lex(FILE *filePtr)
{
    // To check if the input file is correct in terms of syntax.
	int name=0;
	char c;
	int numLine = 1;
	int charCount = 0;
	char tempStr[MAX];
	int i;
	int isValid = 1;

	while((c=fgetc(filePtr))!=EOF)
    {
		if (c == '\n')
			numLine++;

		// Exclude comment line starting with '//' and ending with new line
		if(c == '/')
        {
			if(fgetc(filePtr) == '/')
            {
				while ((c = fgetc(filePtr)) != '\n') {}
				numLine++;
			}
		}

		if(isalnum(c))
        {
			tempStr[charCount] = c;
			charCount++;
			if (charCount > 800)
			{
				printf("Word '%s' on line number %d is too long. \n", tempStr, numLine);
				exit(0);
			}
		}
		else if (isspace(c) || isExAcceptableChar(c))
        {
			charCount = 0;
		}
		else
        {
			printf("Invalid character '%c' at line %d. \n", c, numLine);
			isValid = 0;
		}
	}

	if (isValid == 0) {
		printf("Something wrong with the input file. \n");
		exit(0);
	}

	rewind(filePtr);

    // to retrieve has tokens the function names alone.

    int flag=1;
	while( (c=fgetc(filePtr)) != EOF)
    {
        // To check for data type.
        if(c == 'i' || c == 'f' || c=='v' || c=='b')
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
        // if the input read is a data type.
        if(flag==0)
        {
            c=fgetc(filePtr);

            if(isalpha(c))
            {
                functionname[fnumber][name++]=c;
                while(isalpha(c=fgetc(filePtr)))
                    functionname[fnumber][name++]=c;
                functionname[fnumber][name]='\0';
                fseek(filePtr, -1, SEEK_CUR);
                if((c=fgetc(filePtr))== '(')
                {
                    fnumber++;
                    name=0;
                    while((c=fgetc(filePtr))!=')')
                    {
                        if(c==',')
                        {
                            functionname[fnumber][name]='\0';
                            fnumber++;
                            name=0;
                        }
                        else
                            functionname[fnumber][name++]=c;
                    }
                    /* functionname[0] has the function name.
                       Rest all have the arguments of the function.
                       functionname[1] is assumed to be the data structure passed
                       functionname[n] is assumed to be the 'size' parameter.
                       where n is the last parameter.
                    */
                    return;
                }
                else
                    name=0;
            }
        }
    }
}

int isExAcceptableChar(char c)
{
	if (c == '.' || c == '(' || c == ')' || c == ',' || c =='{' || c == '}' ||
		c == ';' || c == '[' || c == ']' || c == '_' || c == '?' ||
		c == ':' || c == '+' || c == '-' || c == '*' || c == '/' || c == '%' ||
		c == '=' || c == '<' || c == '>' || c == '!' || c == '&' || c == '\'' ||
		c == '"' || c == '\\'|| c == '^' || c == '|'
		 || c == '#'  )
        {
                return 1;
        }
    else
                return 0;
}

void lexdisplay()
{
    printf("Function name: \t");
    puts(functionname[0]);
    int i;
    for(i=1;i<=fnumber;i++)
    {
        printf("%dth parameter:\t",i);
        puts(functionname[i]);
    }
}
