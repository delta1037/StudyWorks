#include <stdio.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverse(struct ListNode* head){
    if(head==NULL||head->next==NULL){
        return head;
    }

    struct ListNode *pre = head;
    struct ListNode* cur=head->next;
    struct ListNode* temp=head->next->next;

    while(cur){
        temp=cur->next;
        cur->next=pre;

        pre=cur;
        cur=temp;

    }

    head->next=NULL;
    return pre;
}

int main() {
    printf("Hello, World!\n");
    return 0;
}