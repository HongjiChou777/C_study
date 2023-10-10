# include <stdio.h>
# include <string.h>
# define MAXLINE 1000

int My_getline(char *line, int max)
{
    int i, c;
    for ( i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    {
        *(line + i) = c;
    }
    
    if (c = '\n')
    {
        *(line + i) = c;
        i++;
    }
    
    *(line + i) = '\0';
    return i;
}

int main(int argc, char *argv[])
{
    char line[MAXLINE];
    long lineno;
    int c, except = 0, number = 0, found = 0;
    
    while (--argc > 0 && (*++argv)[0] == '-')   //(*++argv)[0] 代表寻找命令行的第二个参数中的第一个字符，第一个参数是函数名；
    {
        while (c = *++argv[0])  //因为上面已经(*++argv)了，因此现在的argv是第二个参数向量；
        {
            switch (c)
            {
            case 'x':
                except = 1;
                break;
            case 'n':
                number = 1;
                break;
            default:
                printf("find: illeagal opthin %c\n",c);
                argc = 0;
                found = -1;
                break;
        }
    if (argc != 1)  
    {
        printf("Usage: find -x -n pattern\n");
    }
    else
    {
        while (My_getline(line, MAXLINE) > 0)
        {
            lineno++;
            if ((strstr(line, *argv) != NULL) != except)
            {
                if (number)
                {
                    printf("%ld: ",lineno);
                }
                printf("%s",line);
                found++;
                
            }
            
        }
        
    }
    
        }
        
    }
    


return found;
}