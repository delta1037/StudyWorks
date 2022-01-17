#include <stdio.h>
#include <malloc.h>

typedef struct node{//树的节点
    int e;
    struct node* left;
    struct node* right;
}node,*linknode;

typedef  struct nodelist{//栈的节点
    int elist;
    struct nodelist *next;

}nodelist,*linknodelist;

linknode build(linknode l);
void first_travel(linknode L);
void middle_travel(linknode L);
void last_travel(linknode L);
void pop();
void push(linknode L);

int i=1;
linknodelist last;

void main() {

    //last->next=NULL;
    linknode L = NULL;

    //建立一棵二叉树
    L=build(L);
    //前序遍历
    //printf("dcc");
    //printf("%d,%d,%d",L->e,L->right->e,L->left->e);
    first_travel(L);
    printf("\n");
    //中序遍历
    middle_travel(L);
    printf("\n");
    //后续遍历
    last_travel(L);
    printf("\n");
}
linknode build(linknode L){
    //用递归法建立一棵四层的左斜二叉树
    linknode l=(linknode)malloc(sizeof(node));
    l->e=i;
    l->right=NULL;
    l->left=NULL;
    L=l;
    i++;
    if (i<5){
        l->left=build(l->left);
        l->right=build(l->right);
    }
    return L;
}
void first_travel(linknode L){
    push(L);
    pop();
    if(L->left!=NULL){
        first_travel(L->left);
    }
    if(L->right!=NULL){
        first_travel(L->right);
    }

}
void middle_travel(linknode L){
    push(L);

    if(L->left){
        middle_travel(L->left);
    }
    pop();
    if(L->right){
        middle_travel(L->right);
    }
}
void last_travel(linknode L){
    push(L);
    if(L->left!=NULL){
        last_travel(L->left);
    }
    if(L->right!=NULL){
        last_travel(L->right);
    }
    pop();
}
void pop(){
    linknodelist t;
    t=last;
    printf("%d",last->elist);
    last=last->next;
    free(t);
}
void push(linknode L){
    linknodelist l=(linknodelist)malloc(sizeof(nodelist));
    l->elist=L->e;
    l->next=last;
    last=l;
}
