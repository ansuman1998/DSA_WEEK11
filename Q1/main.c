#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int i,j;
    int a[n];
    for(i=0;i<n;i++)
        scanf("%d", &a[i]);
    i=0;
    j=n-1;
    int profit=0;
    int c=1;
    while(i<=j)
    {
        if(a[i]>=a[j])
        {
            profit+=(a[i]*c);
            i++;
            c++;
        }
        else
        {
            profit+=(a[j]*c);
            j--;
            c++;
        }
    }
    printf("%d\n", profit);
}
