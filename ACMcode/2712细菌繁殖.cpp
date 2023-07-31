#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int n;
	scanf("%d\n",&n);
	while(n--)
	{
		int a[5];
		int day=0;
		for(int i=0;i<5;i++)
		{
			scanf("%d",&a[i]);
		}

		int yue[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

		for(int i=a[0];i<a[3];i++)
		{
		    day = day + yue[i];
		}
		day = day -a[1] + a[4] + 1;
		long b[100];
		b[0] = 0;
		b[1] = a[2];

		for(int i=2;i<=day;i++)
		{
			b[i] = b[i-1]*2;
		}
		printf("%ld\n",b[day]);
	}
	return 0;
}
