#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  M 9
#define N 9

int meza[N][N]={{1,1,1,1,1,1,1,1,1},
                {1,0,0,0,0,1,0,1,1},
                {1,0,0,1,0,0,0,0,1},
                {1,0,0,1,0,1,0,1,1},
                {1,1,0,0,0,1,0,1,1},
                {1,1,0,1,1,1,0,0,1},
                {1,0,0,1,0,0,1,0,1},
                {1,1,0,1,1,0,0,0,1},
                {1,1,1,1,1,1,1,1,1}};
char mezaone[N][N];
typedef struct locate//记录路径
{
    int x;
    int y;
    int c;//代表方向，5是中心，8是上，2是下，4是左，6是右
    int t;
    struct locate *next;//链栈

}locate,*link;

link f;

void print();
link create();
void pass_L(link s);
link judge_L(link s);
link pop(link s);
void push(link l,link s);
void print_L(link l);

int main()
{
    print();//打印输入的迷宫
    link L;
    L=create();//创建一个头结点
    pass_L(L);//寻找路径
    print_L(f);//打印出路径

    return 0;

}
void print()
{
    int i,j;

    printf("迷宫:\n");
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
            mezaone[i][j]=meza[i][j]+'0';
            printf("%d ",meza[i][j]);
        }
        printf("\n");
    }
}
link create()
{
    link L,L1;

    L1=(link)malloc(sizeof(locate));
    L1->c=6;
    L1->x=0;
    L1->y=1;
    L1->next=NULL;

    L=(link)malloc(sizeof(locate));
    L->next=L1;
    L->c=5;
    L->x=1;
    L->y=1;

    return L;
}

void pass_L(link s)//路径
{
    link q;

    if(judge_L(s))//判断后面值
    {
        q=judge_L(s);
        //printf("%d %d\n",q->x,q->y);
        push(q,s);
        pass_L(q);

    }
    else
    {
        if((s->x==M-2)&&(s->y==N-2))
        {
            printf("OK!找到路径");
            f=s;
        }
        else
        {
            meza[s->x][s->y]=1;//留下此路不通的痕迹
            pass_L(pop(s));

        }
    }

}
link pop(link s)//返回此节点前一个节点
{
    link l;
    l=s->next;
    free(s);
    //printf("pop\n");
    return l;
}
void push(link q,link s)//压入，并建立关系
{
    q->next=s;
    meza[s->x][s->y]=s->c;
    //printf("push\n");
}
link judge_L(link s)
{
    link p;
    p=(link)malloc(sizeof(locate));

    //向右
    if(s->next->c!=4&&(meza[(s->x)+1][s->y]==0))
    {
        p->x=(s->x)+1;
        p->y=s->y;
        s->c=6;

        return p;
    }

    //向下
    else if(s->next->c!=2&&(meza[s->x][(s->y)+1]==0))
    {
        p->x=s->x;
        p->y=(s->y)+1;
        s->c=8;

        return p;
    }
    //向上
    else if(s->next->c!=8&&meza[s->x][(s->y)-1]==0)
    {
        p->x=s->x;
        p->y=(s->y)-1;
        s->c=2;

        return p;
    }
    //向左
    else if(s->next->c!=6&&meza[(s->x)-1][s->y]==0)
    {
        p->x=(s->x)-1;
        p->y=s->y;
        s->c=4;

        return p;
    }
    return NULL;
}
void print_L(link l)
{

    int i,j;

    while(l->next)
    {
        if(l->next->c==2)
        {
            mezaone[l->x][l->y]='#';
        }
        else if(l->next->c==8)
        {
            mezaone[l->x][l->y]='#';
        }
        else if(l->next->c==4)
        {
            mezaone[l->x][l->y]='#';
        }
        else if(l->next->c==6)
        {
            mezaone[l->x][l->y]='#';
        }
        l=l->next;
    }
    printf("路径：\n");
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            printf("%c ",mezaone[i][j]);
        }
        printf("\n");
    }
}