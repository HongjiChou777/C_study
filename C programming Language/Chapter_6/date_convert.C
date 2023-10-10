# include <stdio.h>
void month_day(int year, int yearday, int *pmonth, int *pday);
int day_of_year(int year, int month, int day);


 static char daytab[2][13] = 
    {
       {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},     //leap year
       {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}      //normal year
    };

int main(void)
{
    int the_day = 31;
    int the_year = 2023;

    int s = day_of_year(the_year , 2, 28);
    printf("%d\n", s);
    printf("123\n");
    

    return 0;
    
}

//根据年月日获取该该日是当年的哪一天。
int day_of_year(int year, int month, int day)
{
    int i, leap;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;   //普通闰年和世纪闰年
    for ( i = 1; i < month; i++)
    {
        day += daytab[leap][i];
    }

    return day;
    
}


//将某年中第几天的日期表示形式转换为某月某日的形式
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    for ( i = 1; yearday > daytab[leap][i]; i++)
    {
        yearday -= daytab[leap][i];
    }
    
    *pmonth = i;
    *pday = yearday;
}