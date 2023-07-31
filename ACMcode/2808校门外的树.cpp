#include <stdio.h>
int main()
{
	int a[10000]={0};
	int l,m,i=0;
	int sum=0;
	scanf("%d %d",&l,&m);
	for(i=0;i<=l;i++)
	{
		a[i]=1;
	}
	while(m--)
	{
		int t=0,w=0,j=0;
		scanf("%d %d",&t,&w);
		for(j=t;j<=w;j++)
		{
			a[j]=0;
		}
	}
	for(i=0;i<=l;i++)
	{
		if(a[i]==1)
		{
			sum++;
		}
	}
	printf("%d\n",sum);
	return 0;
}
