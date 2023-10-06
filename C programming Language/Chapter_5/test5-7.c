/*
* 将由alloc分配的空间而储存的数据，存放到由main函数定义的数组中，这样可以加快程序运行速率。


*/

# include <stdio.h>
# include <string.h>
# define MAXLINES 5000

char *lineptr[MAXLINES];
#define MAXLEN 1000
char *alloc(int);
char *alloc(int n);
int readlines(char *lineptr[], char *linestor,  int maxlines);

void afree(char *p);
void qsort(char *v[], int left, int right);
void writelines(char *lineptr[], int nlines);
void qsort(char *v[], int left, int right);



int main(void)
{
    int nlines;  //读取输入行的数目
    char *linestor [5000000];
    printf("IN THE FUNCATION!\n");  //find error
    if ((nlines = readlines(lineptr, &linestor,  MAXLINES)) >= 0)
    {
        printf("nlines >= 0\n");    //find er
        ror

        qsort(lineptr, 0, nlines-1);

        printf("qsort FUNCATION done!\n");    //find error


        writelines(lineptr, nlines);
        printf("Finish.");
        return 0;
    }
    else
    {
        printf("error: input too big to sort\n");
        return 1;
    }
       
}

# define MAXSTOR 5000
int readlines(char *lineptr[], char *linestor, int maxlines)
{
    int getline(char s[], int lim);
    int len, nlines;
    char *p = linestor;
    char line[MAXLEN];
    char *linestop = linestor + MAXSTOR;

    while ((len = getline(line, MAXLEN)) > 0)
    {
        if(nlines >= maxlines || (p + len > linestop)) //new line超过上限，或分配的内存空间不足
        {
            return -1;
        }
        else
        {
            line[len -1] = '\0';    //删除换行符
            strcpy(p, line);        //将line，就是现在这行的内容拷贝到刚刚分配的内存空间p中
            lineptr[nlines++] = p;  //将p保存到行指针中
            p += len;
        }
        
    }
    return nlines;  //将读取到的行的数目返回给主函数


   
}

void writelines(char *lineptr[], int nlines)
{
    int i;
    for ( i = 0; i < nlines; i++)
    {
        printf("%s\n",lineptr[i]);  //error:忘记写数组下标i
    }
    
}

int getline(char s[], int lim)
{
    int i, c;
    for (i = 0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; i++)
    {
        s[i] = c;
    }
    
    if (c == '\n')
    {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;

}



//def alloc and afree
#define ALLOCSIZE 10000 

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n) //首地址 + 总大小 - 已分配单元的最后一个单元地址 >= 需要空间 
    {
        allocp += n;        //先加n保存变量
        return allocp - n;  //再减n返回所需地址,(该函数返回char *变量;)
    }
    else
    {
        return 0;
    }
    
}

void afree(char *p)
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
    {
        allocp = p;
    }
    
}

void qsort(char *v[], int left, int right)
{
    void swap_my(char *s[], int i, int j);
    int i, last;
    if (left >= right)  //find error 没有写结束判定语句；
    {
        return;
    }
    
    swap_my(v, left, (left + right)/2);
    last = left;
    for ( i = left+1; i <= right; i++)
    {
        if (strcmp(v[i], v[left]) < 0)
        {
            swap_my(v, ++last, i);  //find error:i写成left；
        }
        
    }
    swap_my(v, last, left);

    qsort(v, left, last-1);
    qsort(v, last+1, right);
    
    
}

void swap_my(char *s[], int i, int j)
{
    int temp;
    temp = *s[i];
    *s[i] = *s[j];
    *s[j] = temp;
}