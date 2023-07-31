#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char q[10],a[201];
    gets(q);
    while(strcmp(q,"START")==0)
    {
        gets(a);
        for(int i=0;a[i]!='\0';i++)
        {
            if(a[i]>=65&&a[i]<=90)
            {
                a[i]=a[i]-5;
                if(a[i]<65)
                a[i]=a[i]+26;
            }
        }
        cout << a << endl;
        gets(q);
        gets(q);
    }
    return 0;
}
//纵观全局
