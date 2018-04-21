#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int main()
{
    int n,i;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    int min=INT_MAX;
    for(i=0;i<n;i++)
        if(a[i]<min)
        min=a[i];

    int c=0;
    int steps=0;
    while(c<n)
    {
        c=0;
        for(i=0;i<n;i++)
        {
            if(a[i]>min)
            {
                if(a[i]-min>=5)
                    a[i]-=5;
                else if(a[i]-min>=3)
                    a[i]-=3;
                else
                    a[i]-=1;
                steps++;
            }
            else
            {
                c++;
            }
        }
    }

    printf("%d\n",steps);
}
