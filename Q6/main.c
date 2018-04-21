#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int n,m,o;
int max(int a, int b)
{
    if(a>=b)
        return a;
    else
        return b;
}
int main()
{
    char s[1000],t[1000],u[1000];
    scanf("%s",s);
    scanf("%s",t);
    scanf("%s",u);
    n=strlen(s);
    m=strlen(t);
    o=strlen(u);

    int a[n+1][m+1][o+1];
    int i,j,k;
    for(i=0;i<=n;i++)
        for(j=0;j<=m;j++)
            for(k=0;k<=o;k++)
            if(i==0 || j==0 || k ==0)
                a[i][j][k]=0;

    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            for(k=1;k<=o;k++)
                if(s[i-1]==t[j-1] && s[i-1]==u[k-1])
                    a[i][j][k]=1+a[i-1][j-1][k-1];
                else
                    a[i][j][k]=max(max(max(a[i-1][j][k],a[i][j-1][k]),a[i][j][k-1]),a[i-1][j-1][k-1]);
    printf("%d\n",a[n][m][o]);

    i=n;
    j=m;
    k=o;
    while(!(i==0 || j==0 || k==0))
    {
        //printf("i %d, j %d, k %d\n",i,j,k);
        if(s[i-1]==t[j-1] && s[i-1]==u[k-1])
        {
            printf("%c",s[i-1]);
            i--;
            j--;
            k--;
        }
        else
        {
            int targeti=i, targetj=j, targetk=k;
            if(a[i-1][j][k]>=a[i][j-1][k] && a[i-1][j][k]>=a[i][j][k-1] && a[i-1][j][k]>=a[i-1][j-1][k-1])
            {
                targeti=i-1;
            }
            else if(a[i][j-1][k]>=a[i-1][j][k] && a[i][j-1][k]>=a[i][j][k-1] && a[i][j-1][k]>=a[i-1][j-1][k-1])
            {
                targetj=j-1;
            }
            else if(a[i][j][k-1]>=a[i-1][j][k] && a[i][j][k-1]>=a[i][j-1][k] && a[i][j][k-1]>=a[i-1][j-1][k-1])
            {
                targetk=k-1;
            }
            else if(a[i-1][j-1][k-1]>=a[i-1][j][k] && a[i-1][j-1][k-1]>=a[i][j-1][k] && a[i-1][j-1][k-1]>=a[i][j][k-1])
            {
                targeti=i-1;
                targetj=j-1;
                targetk=k-1;
            }
            i=targeti;
            j=targetj;
            k=targetk;
        }
    }
    printf("\n");

}
