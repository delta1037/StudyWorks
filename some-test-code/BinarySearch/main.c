#include <stdio.h>
#include <stdbool.h>

bool find(int* num,int numsSize,int target){
    int middle;
    int left=0,right=numsSize-1;

    while (left<=right){
        middle = left + (right - left) / 2;
        //printf("left-right-mid=%d-%d-%d\n",left,right,middle);
        if(num[middle]>target){
            right=middle-1;
        }
        else if(num[middle]==target){
            return true;
        }
        else{
            left=middle+1;
        }
        //printf("left-right==%d-%d\n",left,right);
    }
}

int main() {
    bool b;
    int num[7]={1,4,5,6,8,9,10};
    b=find(num,7,1);
    printf("%d",b);
    return 0;
}