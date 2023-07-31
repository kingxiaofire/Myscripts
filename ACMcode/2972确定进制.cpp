#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;

int display(char *a,int i)//将p,q，r都转化为十进制的数去比较
{
  int n,j,sum=0;
  n = strlen(a);
  for(j=0;j<n;j++)
  {
    if(a[j]-'0'>=i)
    {
      return -1;//字符串中的数不能大于等于进制数
    }
    sum = sum + (a[n-j-1]-'0')*pow(i,j);
  }
    return sum;
}

int main()
{
  char p[9],q[9],r[9];
  while(scanf("%s %s %s",p,q,r)!=EOF)
  {
    int a,b,c,i,t=0;
    for(i=2;i<=16;i++)
    {
      a = display(p,i);
      b = display(q,i);
      c = display(r,i);

      if(a==-1||b==-1||c==-1)
      {
        continue;//如果此次i不符合，则跳出本次循环
      }
      if(a*b==c)
      {
        t = i;
        break;//因为要求输入最小的i，所以要退出循环，不然大的会覆盖
      }

    }
    printf("%d\n",t);
  }
  return 0;
}
