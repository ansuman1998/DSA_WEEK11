#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int gp(int *a, int n)
{
    if(n==0 || n==1)
        return n;
    else if(n==2)
    {
        if(a[1]%a[0]==0)
            return 2;
        else
            return 1;
    }
    int dp[n][n];
    int i;
    for(i=0;i<n;i++)
    {
        if(a[n-1]%a[i]==0 && i!=n-1)
            dp[i][n-1]=2;
        else
            dp[i][n-1]=1;
    }
    printf("Border cases handled\n");

    int max=1;
    int j,k;
    for(j=n-2;j>=2;j--)
    {
        i=j-1;
        k=j+1;
        while(i>=0 && k<n)
        {
            if(a[i]*a[k]<a[j]*a[j])
            {
                k++;
            }
            else if(a[i]*a[k]>a[j]*a[j])
            {
                if(a[j]%a[i]==0)
                    dp[i][j]=2;
                else
                    dp[i][j]=1;
                i--;
            }
            else
            {
                dp[i][j]=dp[j][k]+1;
                if(dp[i][j]>max)
                    {
                        printf("The max is updated by %d %d\n", i, j);
                        max=dp[i][j];
                    }
                i--;
                k++;
            }
        }

        while(i>=0)
        {
            if(a[j]%a[i]==0)
                dp[i][j]=2;
            else
                dp[i][j]=1;
            i--;
        }
    }



    return max;

}
int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    int i;
    for(i=0;i<n;i++)
        scanf("%d", &a[i]);

    printf("%d\n",gp(a,n));
}
