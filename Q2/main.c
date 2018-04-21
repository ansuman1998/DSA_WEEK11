#include <stdio.h>
#include <stdlib.h>
int a[100][100];
int dp1[100];
int dp2[100];
int cost[100];
int n;
void dfs(int parent, int V)
{
    int sum1=0,sum2=0;
    printf("Entered the node %d with parent %d\n",V,parent);
    int j,k;
    for(j=1;j<=n;j++)
        if(a[V][j]==1 && j!=parent)
    {
        dfs(V,j);
        sum1+=dp2[j];
        sum2+=dp1[j];
    }
    sum1+=cost[V];
    dp1[V]=sum1;
    dp2[V]=sum2;
}
int main()
{
   int i,u,v,j;
   scanf("%d", &n);
   //int cost[n+1];


   for(i=1;i<=n;i++)
    scanf("%d", &cost[i]);
   for(i=0;i<=n;i++)
    for(j=0;j<=n;j++)
    a[i][j]=0;

   for(i=1;i<=n-1;i++)
   {
       scanf("%d %d", &u, &v);
       a[u][v]=1;
       a[v][u]=1;
   }

   for(i=1;i<=n;i++)
   {
       for(j=1;j<=n;j++)
        printf("%d ",a[i][j]);
       printf("\n");
   }

   dfs(0,1);
   if(dp1[1]>=dp2[1])
   printf("%d\n",dp1[1]);
   else
    printf("%d\n",dp2[1]);
}
