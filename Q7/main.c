#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int max(int a, int b)
{
    if(a>=b)
        return a;
    else
        return b;

}
int main()
{
    int n,k,i,j,l;
    scanf("%d %d", &n, &k);
    int dp[n+1][k+1];
    for(i=1;i<=n;i++)
    {
        dp[i][1]=i;
    }
    for(j=1;j<=k;j++)
    {
        dp[1][j]=1;
        dp[0][j]=0;
    }
    for(i=2;i<=n;i++)
        for(j=2;j<=k;j++)
    {
        int min=INT_MAX;
        for(l=1;l<=i;l++)
        {
            if(max(dp[i-l][j],dp[l-1][j-1])<min)
                min=max(dp[i-l][j],dp[l-1][j-1]);
        }
        dp[i][j]=min+1;

    }
    for(i=0;i<=n;i++)
    {
        for(j=1;j<=k;j++)
            printf("%d ", dp[i][j]);
        printf("\n");
    }
    printf("%d\n",dp[n][k]);
}
