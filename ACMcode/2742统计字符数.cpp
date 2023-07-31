#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        char a[1000];
        scanf("%s",a);
        int i = 0,max = 0;
        int b[26]={0};

        for(i = 0 ;i < strlen(a); i ++)
        {
           b[a[i]-'a']+=1;
        }

        for(i = 0; i < 26; i ++ )
        {
            if(b[i] > b[max])
            max = i;
        }
        char qwe=max+'a';
        cout <<char(qwe)<< ' ' << b[max] << endl; 
        //printf("%c %d\n",max+'a',b[max]);
    }
}
