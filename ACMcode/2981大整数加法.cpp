#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    char a[201],b[201],xiao[201];
    int  c[1000]={0};
    char ma[201],mi[201];
    gets(a);
    gets(b);
    int len1=strlen(a),len2=strlen(b),max=0,min=0;
    int i=0,j=0,k=0;
    if(len1>=len2)
    {
        max = len1;
        min = len2;
        strcpy(ma,a);
        strcpy(mi,b);
    }
    else 
    {
        max = len2;
        min = len1;
        strcpy(ma,b);
        strcpy(mi,a);
    }
    j=min;
    for(int i=max-1;i>=min;i--)
    {
        xiao[i] = mi[j];
        j--;
    }
    for(int i=min-1;i>=0;i--)
    {
        xiao[i] = '0';
    }
    for(int i=max;i>=0;i--)
    {
        c[k] = c[k] + (ma[i]-'0') + (mi[i]-'0');
        if(c[k]>=10)
        {
            c[k] = c[k]%10;
            c[k+1] = c[k+1] + 1;
        } 
        k++;
    }
    if(c[k]==0)
    {
        k = k-1;
    }
   for(i=k;i>0;i--)
   {
       printf("%d",c[i]);
   }
   printf("\n");
   return 0;
}
