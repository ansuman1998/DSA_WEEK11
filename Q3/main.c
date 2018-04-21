#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct stones
{
    int w;
    int c;
};
int main()
{
    int t,n,m,x,i,j;
    scanf("%d", &t);
    while(t!=0)
    {
        scanf("%d %d %d", &n,&m,&x);
        struct stones stone[n];
        for(i=0;i<n;i++)
            scanf("%d",&stone[i].w);
        for(i=0;i<n;i++)
            scanf("%d",&stone[i].c);


        for(i=1;i<n;i++)
        {
            j=i-1;
            int w=stone[i].w;
            int c=stone[i].c;
            while(j>=0 && stone[j].w>w)
                {
                    stone[j+1].w=stone[j].w;
                    stone[j+1].c=stone[j].c;
                    j--;
                }
            j++;
            stone[j].w=w;
            stone[j].c=c;

        }

          for(i=1;i<n;i++)
        {
            j=i-1;
            int w=stone[i].w;
            int c=stone[i].c;
            while(j>=0 && stone[j].c>c)
                {
                    stone[j+1].w=stone[j].w;
                    stone[j+1].c=stone[j].c;
                    j--;
                }
            j++;
            stone[j].w=w;
            stone[j].c=c;

        }

        int point[m+1];
        for(i=1;i<=m;i++)
            point[i]=-1;

        for(i=0;i<n;i++)
        {
            if(point[stone[i].c]==-1)
                point[stone[i].c]=i;
        }

        printf("Behold the initital pointers\n");


        printf("\n");

        int possible;
        int answer;
        do
        {
            for(i=1;i<=m;i++)
            printf("Pointer for %d is %d\n",i, point[i]);
            printf("\n");

            int sum=0;
            for(i=0;i<m;i++)
            {
                sum+=stone[point[i]].w;
            }

                if(sum<x)
                    {
                        possible=1;
                        answer=sum;
                    }
                else
                    possible=0;

            int min=INT_MAX, minindex;
            for(i=1;i<=m;i++)
            {
                if((point[i]+1)<n && stone[point[i]+1].c==stone[point[i]].c && stone[point[i]+1].w<min)
                {
                    min=stone[point[i]+1].w;
                    minindex=i;
                }
            }
            if(min==INT_MAX)
                possible=0;
            else
            {
                point[minindex]++;
            }

        }while(possible==1);

        printf("%d\n",x-answer);
        t--;
    }
}
