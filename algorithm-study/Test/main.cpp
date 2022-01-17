#include <iostream>

int main()
{
    int result=0;
    int i=0;

    int num1=0;
    int num2=0;

    char s[10];
    //获取整个字符串
    scanf("%s",s);
    //获取第一个数字
    while (s[i]>='0'&&s[i]<'9'){
        num1=s[i]-'0'+num1*10;
        i++;
    }
    //获取中间运算符
    char fu_hao=s[i];
    i++;
    //获取第二个数字
    while (s[i]>='0'&&s[i]<'9'&&s[i]!='\0'){
        num2=s[i]-'0'+num2*10;
        i++;
    }
    //根据中间运算符进行计算
    switch (fu_hao){
        case '-':
            result=num1-num2;
            break;
        case '+':
            result=num1+num2;
            break;
        case '*':
            result=num1*num2;
            break;
        case '/':
            result=num1/num2;
        default:break;
    }
    //输出结果
    printf("%s=%d",s,result);
    return 0;
}