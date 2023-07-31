#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int a=0,b=0,c=0,d=0,e=0,f=0,sum = 0;
	while(scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f)!=EOF)
	{
		if(a==0&&b==0&&c==0&&d==0&&e==0&&f==0) break;
		int ak=0,bk=0;

		sum = f + e + d;
		ak = e*11;
		bk = d*5;

		if(c%4==0)
		{
			sum = sum + c/4;
		}
		if(c%4==1)
		{
			sum = sum + c/4 + 1;
			bk = bk + 5;
			ak = ak + 7;
		}
		if(c%4==2)
		{
			sum = sum + c/4 + 1;
			bk = bk + 3;
			ak = ak + 6;
		}
		if(c%4==3)
		{
			sum = sum + c/4 + 1;
			bk = bk + 1;
			ak = ak + 5;
		}

		if(b==bk)
		{
			b = 0;
			bk =0;
		}
		if(b>bk)
		{
			b = b - bk;

			if(b%9==0)
			{
				sum = sum + b/9;
				b = 0;
			}
			if(b%9!=0)
			{
				sum = sum + b/9 +1;
				ak = ak + 4*(9 - b%9);
			}
		}
		 else if(b<bk)
		{
			bk = bk - b;
			ak = ak + 4*bk;
		}

		if(a<=ak)
		{
			a = 0;
		}
		else if(a>ak)
		{
			a = a - ak;
			if(a%36==0)
			{
				sum = sum + a/36;
			}
			if(a%36!=0)
			{
				sum = sum + a/36 + 1;
			}
		}

		printf("%d\n",sum);
	}
	return 0;
}


我并没有用到什么高级算法，就是挨个情况分析：
一个6*6 的有一个就单独占用一个箱子，没有多余空间；
一个5*5 的多余了11个1*1的空间；
一个4*4 的多余了5个2*2的空间；
3*3 分4种情况：
               （1）个数为4的倍数：无多余空间
               （2）个数为4的倍数加1:有5个2*2和7个1*1的多余空间
               （3）个数为4的倍数加2:有3个2*2和6个1*1的多余空间
               （4）个数为4的倍数加3:有1个2*2和5个1*1的多余空间
               
               
然后分析2*2和1*1的就行
