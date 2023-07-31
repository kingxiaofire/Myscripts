#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstring>
using namespace std;

void strrevl(char *s)
{
    int len = strlen(s);
    char t=0;
    int mid;
    mid = len/2;
    for(int i=0;i<mid;i++)
    {
        t = s[i];
        s[i] = s[len-i-1];
        s[len-i-1] = t;
    }
	return ;
}
char a[100][101];//以二维数组的形式输入
int main()
{
    int t=0;
    scanf("%d\n",&t);
    while(t--)
    {
		memset(a, 0, sizeof(a));
        int n;
        scanf("%d\n",&n);
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
        }

        char subStr[101];//存放最小子串
        char revsubStr[101];//存放最小子串的反串
        int sublen = strlen(a[0]);
        int sourcelen = strlen(a[0]);
        while(sublen > 0) //从最大的子串开始找
        {
            int flag=0;
            for(int i=0;i <= sourcelen-sublen; ++ i)//枚举所有子串
            {
                strncpy(subStr,a[0]+i,sublen);
                strncpy(revsubStr,a[0]+i,sublen);
                subStr[sublen] = revsubStr[sublen] = '\0';
                strrevl(revsubStr);
                bool find = true;

                for(int j = 1;j != n; ++ j)
                {
                    if(strstr(a[j],subStr) == NULL && strstr(a[j] ,revsubStr) == NULL)//strstr函数返回字符串中首次出现子串的地址
                    {
                        find = false;
                        break;//不满足就结束本次循环
                    }
                }
                if(find)
                {
                    flag =1;//因为要求最大的，所以出现时就退出，不然会越来越小的
                    break;
                }
            }
            if(flag == 1)
            break;
            sublen--;
        }
        cout << sublen << endl;
    }
    return 0;
}
