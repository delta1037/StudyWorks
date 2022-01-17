#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char c;
    struct node *next;

}node,*link;

typedef struct
{
    link front;//队头指针
    link rear;//队尾指针
}linkq;

void pailie();
linkq create();
linkq enqueue(linkq q,char c);
linkq dequeue(linkq q);


int main()
{
    pailie();
    return 0;
}
linkq create()
{
    linkq L;
    L.front=L.rear=(link)malloc(sizeof(node));
    L.front->next=NULL;
    return L;
}
linkq enqueue(linkq q,char e)
{
    link p;
    p=(link)malloc(sizeof(node));
    p->c=e;
    p->next=NULL;

    q.rear->next=p;
    q.rear=p;

    return q;
}
linkq dequeue(linkq q)
{
    link p;

    if(q.front==q.rear)
    {
        printf("error");

    }
    p=q.front->next;

    q.front->next=p->next;
    if(q.rear==p)
    {
        q.rear=q.front;
    }
    free(p);
    return q;
}
void pailie()
{
    int n=0,i,minc,x,z,d;
    int k;
    linkq chedao[10];
    char a[10];
    linkq che;
    linkq minlinkq;

    printf("一共输入几辆车:");
    scanf("%d",&x);

    printf("输入火车的序号:\n");
    scanf("%s",a);

    //将各序号按顺序填入各车道内
    for(z=0;a[z]!='\0';z++)
    {
        //判断是否能接在现有的车道的后面
        k=0;
        for(i=0;i<n;i++)
        {
            if(a[z]>chedao[i].rear->c)
            {
                chedao[i]=enqueue(chedao[i],a[z]);
                //printf("%c lao\n",a[z]);

                k=1;
                break;
            }

        }
        if(k==0)//否则创建一个新的车道
        {
            chedao[n]=create();

            chedao[n]=enqueue(chedao[n],a[z]);
            //printf("%c  xin\n",chedao[n].front->next->c);
            n++;
        }
    }

    //创建一个新车道，将各车道内的车
    che=create();

    //将各车道上的车接入到
    for(;z>0;z--)
    {
        //判断有不空的车道
        for(i=0;i<n;i++)
        {
            if(chedao[i].front==chedao[i].rear)
            {
                chedao[i].front=NULL;
                chedao[i].rear=NULL;
                //printf("nz\n");
            }

        }
       // printf("cz\n");

        //找现在的车道的最小值，并接入主车道上
        minc=100;
        for(i=0;i<n;i++)
        {
            if((chedao[i].front!=NULL)&&((chedao[i].front->next->c)<minc))
            {
                d=i;
                minc=chedao[i].front->next->c;

            }
        }
        //printf("%d",d);
        //printf("%c \n",chedao[d].front->next->c);
        che=enqueue(che,chedao[d].front->next->c);//接入
        chedao[d]=dequeue(chedao[d]);//删除接入的节点
    }
    while(che.front!=che.rear)
    {
        printf("%c \n",che.front->next->c);
        che=dequeue(che);
    }

}