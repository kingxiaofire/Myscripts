#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    int day;
    while(scanf("%d",&day)!=EOF)
    {
        if(day==-1) break;
        int zong,i;
        int week=day%7;
        char xq[7][10]={"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};
        int yue[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

        int year = 2000;

        if((year%4==0&&year%100!=0)||year%400==0)
             zong = 366;

        while(day>=zong)
        {
            day = day - zong;
            year ++;
            if((year%4==0&&year%100!=0)||year%400==0)
                zong = 366;
            else
                zong = 365;
        }

        if((year%4==0&&year%100!=0)||year%400==0)
            yue[1] = 29;
        else
            yue[1] = 28;

        for(i=0;day>=yue[i];i++)
            day = day - yue[i];
            day = day + 1;
        printf("%04d-%02d-%02d %s\n",year,i+1,day,xq[week]);
    }
        return 0;
}
