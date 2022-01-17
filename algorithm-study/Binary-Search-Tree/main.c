#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <stdlib.h>

struct node {
    struct node* left;
    struct node*right;
    int data;
};

typedef  struct nodelist{//栈的节点
    int elist;
    struct nodelist *next;

}nodelist,*linknodelist;

typedef struct node Node;
//初始化
Node* init(Node* root);
//插入
Node* insert(Node* root,int data);
//删除
Node* delete(Node* root,int data);
//销毁
void deinit(Node* root);
//中序遍历放到数组arr中
void inoder(struct node *root,int* arr);
void push(Node* root);
int pop();
//判断一棵树是否是bst
bool isValidBST(Node*root);
//寻找BST中,两节点值之差的最小值
int getMininumDifference(int* arr);

linknodelist last;
int i=0;
int main() {
    Node *root = NULL;
    root=init(root);

    int data=11;
    root=insert(root,data);

    int arr1[11];
    inoder(root,arr1);
    printf("\n");
    for(int i=0;i<10;i++){
        printf("%d",arr1[i]);
    }

    root=delete(root,data);

    int arr[10];
    inoder(root,arr);
    printf("\n");
    for(int i=0;i<10;i++){
        printf("%d",arr[i]);
    }

    printf("\n");
    bool b;
    b=isValidBST(root);
    printf("%d\n",b);


    int m;
    m=getMininumDifference(arr);
    printf("%d",m);

    deinit(root);
    return 0;
}

Node* init(Node* root){
    //give an arry
    int arry_init[10]={5,3,8,0,4,1,2,7,9,6};
    int i;
    root=(Node*)malloc(sizeof(struct node));
    root->right=NULL;
    root->left=NULL;
    root->data=arry_init[0];

    Node* L;

    for(i=1;i<10;i++){

        L=root;

        Node* ln=(Node*)malloc(sizeof(struct node));
        ln->right=NULL;
        ln->left=NULL;
        ln->data=arry_init[i];

        int flag=0;
        while(flag==0){
            if(L->data>arry_init[i]){
                if(L->left==NULL){
                    L->left=ln;
                    flag=1;
                }
                L=L->left;
            }
            else{
                if(L->right==NULL){
                    L->right=ln;
                    flag=1;
                }
                L=L->right;
            }
        }

    }

    return root;

}

Node* insert(Node* root,int data){
    Node* ln=(Node*)malloc(sizeof(struct node));
    ln->right=NULL;
    ln->left=NULL;
    ln->data=data;

    Node* L=root;

    int flag=0;
    while(flag==0){
        if(L->data>data){
            if(L->left==NULL){
                L->left=ln;
                flag=1;
            }
            L=L->left;
        }
        else{
            if(L->right==NULL){
                L->right=ln;
                flag=1;
            }
            L=L->right;
        }
    }

    return root;
}

Node* delete(Node* root,int data){
    Node* x=root;
    int flag=0;
    while(flag==0&&x!=NULL){
        if((x->data)>data){

            if(x->left->data==data){
                Node* x1;
                Node* x2;
                x1=x;
                x2=x;

                if(x->left->right==NULL&&x->left->left==NULL){
                    x->left=NULL;
                }
                else{
                    if(x1->left->right!=NULL){
                        x1=x1->left->left;
                        while(x1->right!=NULL){
                            x1=x1->right;
                        }
                        x1->right=x->left->right;
                    }
                    if(x2->left->left!=NULL){
                        x2->left=x2->left->left;
                    }
                }
                flag=1;
            }

            x=x->left;
        }
        else{
            if(x->right->data==data){
                Node* x1;
                Node* x2;
                x1=x;
                x2=x;

                if(x->right->right==NULL&&x->right->left==NULL){
                    x->right=NULL;
                }
                else{
                    if(x1->right->left!=NULL){
                        x1=x1->right->right;
                        while(x1->left!=NULL){
                            x1=x1->left;
                        }
                        x1->left=x->right->left;
                    }
                    if(x2->right->right!=NULL){
                        x2->right=x2->right->right;
                    }
                }
                flag=1;
            }
            x=x->right;
        }
    }

    if (x == NULL) {
        if (flag == 0) {
            printf("不存在");
            return root;
        }
    }

    return root;

}

void deinit(Node* root){
    //递归free
    if(root->right==NULL&&root->left==NULL){
        free(root);
    }

    if(root->left!=NULL){
        deinit(root->left);
    }
    if(root->right!=NULL){
        deinit(root->right);
    }
}

void inoder(struct node *root, int* arr) {
    push(root);

    if(root->left){
        inoder(root->left,arr);
    }
    arr[i]=pop();
    i++;
    if(root->right){
        inoder(root->right,arr);
    }
}

void push(Node* root){
    linknodelist l=(linknodelist)malloc(sizeof(nodelist));
    l->elist=root->data;
    l->next=last;
    last=l;
}

int pop(){
    linknodelist t;
    int data;
    t=last;
    printf("%d",last->elist);
    last=last->next;
    data=t->elist;
    free(t);
    return data;
}


bool isValidBST(Node* root){
    //递归? :二叉搜索树的两侧均是二叉搜索树
    bool b1=true;
    bool b2=true;
    bool b3=false;

    int bn1=1;
    int bn2=1;
    if(root->right!=NULL||root->left!=NULL){//判断本节点

        if(root->right!=NULL&&root->right->data<root->data){
            bn1=0;
        }

        if(root->left!=NULL&&root->left->data>root->data){
            bn2=0;
        }

        if(bn1&&bn2){
            b3=true;
        }
    }

    //递归
    if(root->left!=NULL){
        if(root->left->right!=NULL||root->left->left!=NULL){
            b1=isValidBST(root->left);
        }
    }
    if(root->right!=NULL){
        if(root->right->right!=NULL||root->right->left!=NULL){
            b2=isValidBST(root->right);
        }
    }


    return b1&&b2&&b3;

}

int getMininumDifference(int* arr){
    int min;
    min=abs(arr[1]-arr[0]);
    for(int i=2;i<10;i++){
        if(abs(arr[i]-arr[i-1])<min){
            min=abs(arr[i]-arr[i-1]);
        }
    }
    return min;

}