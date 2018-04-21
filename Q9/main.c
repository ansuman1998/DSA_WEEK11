#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
int min(int a, int b)
{
    if(a<b)
        return a;
    else
        return b;
}
int main()
{
    char s[100],t[100];
    scanf("%s", s);
    scanf("%s", t);
    int n=strlen(s);
    int m=strlen(t);
    int a[n+1][m+1],i,j;
    if(s[0]==t[0])
        a[1][1]=0;
    else
        a[1][1]=1;
    for(i=2;i<=n;i++)
        a[i][1]=a[i-1][1]+1;
    for(j=2;j<=m;j++)
        a[1][j]=a[1][j-1]+1;

    for(i=2;i<=n;i++)
        for(j=2;j<=m;j++)
    {
        if(s[i-1]==t[j-1])
        {
            a[i][j]=a[i-1][j-1];
        }
        else
        {
            a[i][j]=1+min(a[i-1][j-1],min(a[i][j-1],a[i-1][j]));
        }
    }

    printf("%d\n",a[n][m]);



}
