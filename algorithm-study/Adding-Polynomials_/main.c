#include <stdio.h>
#include <stdlib.h>

typedef struct linklist
{
    int exp;
    int coe;
    struct linklist *next;
}linklist,*link;

link create_L(int n);
link sort_L(link L,int n);
void print_L(link L);
link add_L(link L1,link L2);

int main()
{
    int n1,n2;
    link L1,L2,L3;

    printf("第一个多项式一共输入几组数据:");
    scanf("%d",&n1);
    printf("第二个多项式一共输入几组数据:");
    scanf("%d",&n2);

    L1=create_L(n1);//创建两个链表
    L2=create_L(n2);

    L1=sort_L(L1,n1);//对两个链表进行排序
    L2=sort_L(L2,n2);

    L3=add_L(L1,L2);//相加

    print_L(L3);//打印

    return 0;
}
link create_L(int n)
{
    int i;
    link L;
    link p = NULL,q;
    L=(link)malloc(sizeof(linklist));//生成头结点
    L->next=NULL;
    q=L;
    printf("开始输入数据:\n常数 指数\n");

    for(i=1;i<=n;i++)
    {
        p=(link)malloc(sizeof(linklist));
        scanf("%d%d",&p->coe,&p->exp);
        q->next=p;
        q=q->next;
    }
    p->next=NULL;
    return L;
}
link sort_L(link L,int n)//首先对两个多项式进行排序
{
    int i,j;
    int t,t1;

    link Lj;

    for(i=0;i<n-1;i++)
    {
        for(Lj=L->next,j=0;j<n-1-i;j++,Lj=Lj->next)
        {
            if(Lj->exp>Lj->next->exp)
            {
                t=Lj->exp;
                Lj->exp=Lj->next->exp;
                Lj->next->exp=t;

                t1=Lj->coe;
                Lj->coe=Lj->next->coe;
                Lj->next->coe=t1;
            }
        }
    }
    return L;
}
link add_L(link L1,link L2)//多项式相加程序
{
    link pa,pb,pc,L;
    link t;
    pa=L1->next;
    pb=L2->next;
    L=pc=L1;
    while(pa&&pb)
    {
        if((pa->exp)<(pb->exp))
        {
            pc->next=pa;
            pc=pa;
            pa=pa->next;
        }
        else if(pa->exp==pb->exp)
        {
            if((pa->coe+pb->coe)==0)
            {
                pa=pa->next;
                pb=pb->next;
            }
            else
            {
                pc->next=pa;
                pc=pa;
                pc->coe=pa->coe+pb->coe;
                pa=pa->next;
                pb=pb->next;
            }
        }
        else
        {
            pc->next=pb;
            pc=pb;
            pb=pb->next;
        }

    }
    pc->next=(pa? pa:pb);
    return L;
}

void print_L(link L)
{
    link pc=L->next;
    while(pc->next)//整合相同元素的程序
    {
        if(pc->exp==pc->next->exp)
        {
            pc->coe=pc->coe+pc->next->coe;
            pc->next=pc->next->next;
        }
        pc=pc->next;
    }
    link p=L;
    p=p->next;
    while(p)//输出多项式
    {
        if(p->exp!=0)
        {
            if(p->coe==1)
            {
                printf("x");
                printf("^");
                printf("%d",p->exp);
            }
            else
            {
                printf("%d",p->coe);
                printf("*x");
                printf("^");
                printf("%d",p->exp);
            }

            if(p->next!=NULL)
            {
                printf("+");
            }
        }
        else
        {
            printf("%d",p->coe);
        }
        p=p->next;

    }


    printf("\n");

}