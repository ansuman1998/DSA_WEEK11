#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int n,m;
int max(int a, int b)
{
    if(a>=b)
        return a;
    else
        return b;
}
int main()
{
    char s[1000],t[1000];
    scanf("%s",s);
    scanf("%s",t);
    n=strlen(s);
    m=strlen(t);

    int a[n+1][m+1];
    int i,j;
    for(i=0;i<=n;i++)
        a[i][0]=0;
    for(j=0;j<=m;j++)
        a[0][j]=0;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        if(s[i-1]==t[j-1])
            a[i][j]=1+a[i-1][j-1];
        else
        a[i][j]=max(max(a[i-1][j],a[i][j-1]),a[i-1][j-1]);
    printf("%d\n",a[n][m]);
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    i=n;
    j=m;
    while(!(i==0 || j==0))
    {
        if(s[i-1]==t[j-1])
        {
            printf("%c",s[i-1]);
            i--;
            j--;
        }
        else
        {
            int targeti=i, targetj=j;
            if(a[i][j-1]>=a[i-1][j] && a[i][j-1]>=a[i-1][j-1])
            {
                targetj=j-1;
            }
            else if(a[i-1][j]>=a[i-1][j-1] && a[i-1][j]>=a[i][j-1])
            {
                targeti=i-1;
            }
            else if(a[i-1][j-1]>=a[i][j-1] && a[i-1][j-1]>=a[i-1][j])
            {
                targeti=i-1;
                targetj=j-1;
            }
            i=targeti;
            j=targetj;
        }
    }
    printf("\n");

}
