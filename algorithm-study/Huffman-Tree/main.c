#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int min;
    int max;

    struct node *leftchild;
    struct node *rightchild;

}node,*link;

void scan_node();//录入
void paixu();//排序

link create_node(int i);//创建树
link create_tree();
void build_tree(link T,int i);

void bianma_tree(link T,int i,int j);//编码
void print_tree(link T);

float ratio[5];//存储每个分数段的比例
int part[5][2];//存储最大最小值
int jieguo[5][5];//存储最后的结果

int main()
{
    link T;
    scan_node();
    paixu();

    T=create_tree();
    print_tree(T);

    return 0;
}

void scan_node()//对数值进行录入
{
    int i;
    printf("59及其以下的比例：");
    scanf("%f",&ratio[0]);
    part[0][0]=0;
    part[0][1]=59;

    for(i=1;i<5;i++)
    {
        printf("%d到%d的比例：",10*i+50,10*i+(i==4? 60:59));
        scanf("%f",&ratio[i]);
        part[i][0]=10*i+50;
        part[i][1]=10*i+(i==4? 60:59);
        printf("\n");
    }
}
void paixu()//对输入的各分数的比例从大到小进行排序
{
    int i,j,t;
    int z;
    float t1;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4-i;j++)
        {
            if(ratio[j]<ratio[j+1])
            {
                t1=ratio[j];
                ratio[j]=ratio[j+1];
                ratio[j+1]=t1;

                for(z=0;z<2;z++)
                {
                    t=part[j][z];
                    part[j][z]=part[j+1][z];
                    part[j+1][z]=t;
                }
            }
        }
    }
}
link create_node(int i)//创建树中的每一个节点 并且返回这个节点
{
    link Q;
    Q=(link)malloc(sizeof(node));

    Q->leftchild=NULL;
    Q->rightchild=NULL;

    Q->min=part[i][0];
    Q->max=part[i][1];

    return  Q;
}
link create_tree()
{
    int i;
    //创建头结点
    link T;
    T=(link)malloc(sizeof(node));

    T->leftchild=NULL;
    T->rightchild=NULL;

    T->min=part[0][0];
    T->max=part[0][1];

    for(i=1;i<5;i++)
    {
        build_tree(T,i);
    }
    return T;
}
void build_tree(link T,int i)//从树根开始分析，判断下一个节点的位置
{
    if(!T->leftchild&&part[i][1]<T->min)//连接到左子树上
    {
        T->leftchild=create_node(i);
    }
    else if(T->leftchild&&part[i][1]<T->min)
    {
        T=T->leftchild;
        build_tree(T,i);
    }

    if(!T->rightchild&&part[i][0]>T->max)//连接到右子树
    {
        T->rightchild=create_node(i);
    }
    else if(T->rightchild&&part[i][1]>T->max)
    {
        T=T->rightchild;
        build_tree(T,i);
    }
}
void bianma_tree(link T,int i,int j)//对路径进行编码
{
    if(T->min<10*i+55&&T->max>10*i+55)
    {
        jieguo[i][j]=2;
    }
    else if(10*i+55<T->min)
    {
        T=T->leftchild;
        jieguo[i][j]=0;
        j++;
        bianma_tree(T,i,j);
    }
    else if(10*i+55>T->max)
    {
        T=T->rightchild;
        jieguo[i][j]=1;
        j++;
        bianma_tree(T,i,j);
    }
}
void print_tree(link T)
{
    int i,j;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            jieguo[i][j]=0;
        }
    }
    for(i=0;i<5;i++)
    {
        j=0;
        bianma_tree(T,i,j);
    }
    printf("最终结果:(其中0代表向左，1代表向右，2代表找到对应的级别)\n");
    for(i=0;i<5;i++)
    {
        printf("%d级:",5-i);
        for(j=0;jieguo[i][j]!=2;j++)
        {
            printf("%d",jieguo[i][j]);
        }
        printf("2");
        printf("\n");
    }
}
