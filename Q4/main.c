#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int a[1000];
int dp[1000][1000];
int mini(int a, int b)
{
    if(a<b)
        return a;
    else
        return b;
}
int sum(int i, int j)
{
    int sum=0;
    int k;
    for(k=i;k<=j;k++)
        {
            sum+=a[k];
        }
    return sum%100;
}
int minimize(int i, int j)
{
    if(i>=j)
        {
            dp[i][j]=0;
            return dp[i][j];
        }
    if(dp[i][j]!=-1)
        {
            printf("DP to the rescue for i %d j %d\n", i, j);
            printf("DP is %d\n", dp[i][j]);
            return dp[i][j];
        }
    int k;
    dp[i][j]=INT_MAX;
    int var=0;
    for(k=i;k<=j;k++)
    {

            var=minimize(i,k);
            var+=minimize(k+1,j);
            var+=sum(i,k)*sum(k+1,j);
            printf("Var is %d\n", var);
            dp[i][j]=mini(dp[i][j],var);
            printf("Min is %d for i %d and j %d\n", dp[i][j],i,j);
    }
    return dp[i][j];
}
int main()
{
   int n;
   scanf("%d", &n);
   int i;
   for(i=0;i<n;i++)
    scanf("%d", &a[i]);
   memset(dp,-1,sizeof(dp));
   printf("%d\n",minimize(0,n-1));
}
