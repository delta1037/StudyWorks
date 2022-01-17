#include <stdio.h>

/**题目来源：算法爱好者：网易2017校园招聘
 *
 * 题目描述：
 * 给定一个数组，除了一个数出现了一次之外其余数都出现了三次，找出出现一次的那个数字
 * 题目要求：线性时间复杂度，不能使用额外的空间
 * 样例输入：
 *      4
 *      0005
 * 样例输出：
 *      5
 *
 * 参考评论中的解法：
 * 采用三进制加法
 *
 */

int Findtheonlyone(int* num,int numsSize){

    int last=num[0],next;
    int lastnumber[20]={0},nextnumber[20]={0};
    int i=0,j;



    if(last==0){
        lastnumber[i]=last;
    }else{
        while (last>0){
            lastnumber[i]=last%3;
            last=last/3;
            i++;
        }
    }



    for(i=1;i<numsSize;i++){
        next=num[i];

        j=0;

        if(next==0){
            nextnumber[j]=next;
        }else{
            while (next>0){
                nextnumber[j]=next%3;
                next=next/3;
                j++;
            }
        }

        for(j=0;j<20;j++){
            if(lastnumber[j]+nextnumber[j]<3){
                lastnumber[j]=lastnumber[j]+nextnumber[j];
            }else{
                lastnumber[j]=(lastnumber[j]+nextnumber[j])%3;
            }
        }



    }
    int sum=0;
    for(int k=0;k<20;k++){
        printf("%d ",lastnumber[k]);
    }
    printf("\n\n");
    j=19;
    while (lastnumber[j]==0){
        j--;
    }
    while (j>=0){
        sum=sum*3+lastnumber[j];
        j--;
    }
    return sum;
}


int main() {
    int result;
    int num[7]={1,2,1,2,1,2,7};
    result=Findtheonlyone(num,7);
    printf("%d",result);
    return 0;
}