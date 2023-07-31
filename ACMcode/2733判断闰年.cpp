#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF&&(1<n&&n<3300))
	{
		if(n%4==0)
		{
			if(n%100==0&&n%400!=0||n%3200==0)
			printf("N\n");
			else 
			printf("Y\n");
		}
		else 
		printf("N\n");
	}
	return 0;
}
