#include <stdio.h>
#include <malloc.h>

/**题目来源：算法爱好者
 * 题目：表达式展开
 * 题目描述：
 *  给出一个表达式s，此表达式包括数字、字母以及方括号。在方括号
 * 前的数字表示方括号内容的重复次数（括号内可以是字符串或者另一
 * 个表达式，编写程序将这个表达式展开
 */

int expand(char* s,int zero,char* num,int index,int nums){
    int i=0,j;
    for(i=0;i<nums;i++){
    j=zero;
        while (s[j]!=']'){
         if(s[j]-'0'>=0&&s[j]-'0'<10){
          index=expand(s,&(j)+2,num,index,(int)s[j]-'0');
          }
          num[index]=s[j];
       index++;
       j++;
        }
        }
    return index;
}
int main() {
    char* s="ss3[aaa]aa";
    char* num=(char*)malloc(1000*sizeof(char));
    int index=0;
    int i;
    printf("%d\n",'3'-'0');
    for(*i=0;s[*i]!='\0';(*i)++){
        int j=s[i]-'0';
        if(j>=0&&j<10){
          //提取数字
           index=expand(s,i+2,num,index,s[*i]-'0');
        }
        num[index]=s[i];
        index++;
    }

    printf("%s",num);
    return 0;
}