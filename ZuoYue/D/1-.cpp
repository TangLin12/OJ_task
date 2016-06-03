#include <stdio.h>
#include <stdlib.h>
int c[1001];
struct biao
{
    int x;
    struct biao *next;
};
struct biao p[1001];
int suan(int x,int y)
{
    struct biao *a;
    c[x]=1;
    if(x==y)
    {
        return 1;
    }
    else
    {
        a=&p[x];
        while(a->next!=NULL)
        {
            a=a->next;
            if(c[a->x]==0)
            {
                if(suan(a->x,y)==1)
                {
                    return 1;
                }
            }
        }
        return 0;
    }
}
int main ()
{
    int n,m,i,j,x,y;
    struct biao *a,*b;
    scanf ("%d",&n);
    for(i=0;i<1000;i++)
    {
        p[i].x=i;
        p[i].next=NULL;
    }
    for(i=0;i<n;i++)
    {
        scanf ("%d",&m);
        for(j=1;j<m;j++)
        {
            scanf ("%d",&y);
            if(j==1)
            {
                x=y;
                a=&p[x];
            }
            else
            {
                b=(struct biao *)malloc(sizeof(struct biao));
                b->x=y;
                b->next=NULL;
                a->next=b;
                a=b;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<1001;j++)
        {
            c[j]=0;
        }
        scanf ("%d %d",&x,&y);
        if(suan(x,y)==1)
        {
            printf ("Yes\n");
        }
        else
        {
            printf ("No\n");
        }
    }
    return 0;
}