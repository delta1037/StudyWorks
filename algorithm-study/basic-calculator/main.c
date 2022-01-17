#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

double exp();
double term();
double factor();
char getPrintableChar();
void match(char expectedToken);
void error();
void untoken(char* a);

char token;  //用于存储读取到的字符，不包括数字

/**
 * 扩展巴科斯范式:利用递归下降分析
 * exp-->exp+term|term
   term-->term*factor|factor
   factor-->(exp)|number
   number-->number digit|digit
   digit-->0|1|2|3|4|5|6|7|8|9
 * c语言-简单计算器的实现
 * 支持 + - * /四则运算
 * 支持( )  括号可以嵌套
 * 输入字符仅限于0-9 + - * / ( )
 * 程序可以进行多次计算,手动退出关闭
 *
 * @return
 */

int main()
{
    double result;
    double save[20];
    char s[20][20];
    int i,t=0;

    printf("退出程序：q\n查询历史记录：f \n");

    for (;;)
    {
        untoken(s[t]);
        //printf("%s\n",s[t]);

        //untoken(s[t]);
        //printf("%s\n",s[t]);

        token = getPrintableChar();
        if (token == 'q')
            break;

        if(token == 'f'){
            for(i=0;i<t;i++){
                printf("%s=%.2lf\t\n",s[i],save[i]);
            }
        }else if(token!= '\n'){

            result = exp();
            save[t]=result;
            t++;

            if (token == '\n')
                printf("Result is: %g\n", result);
            else
                error();

        }
    }

    return 0;
}
/**
 * 按照首先计算括号里的内容，然后计算乘除，后算加减的顺序
 * 即        factor       term         exp
 * exp调用term term调用factor factor调用exp
 *

 */
double exp() {  //计算加减
    double temp = term();
    while (token == '+' || token == '-'){
        switch(token) {
            case '+': match('+');
                temp += term();
                break;
            case '-': match('-');
                temp -= term();
                break;
            default:break;
        }
    }
    return temp;
}

double term() {    //计算乘除
    double temp = factor();
    while (token == '*' || token == '/'){
        switch(token) {
            case '*': match('*');
                temp *= factor();
                break;
            case '/': match('/');
                temp /= factor();
                break;
            default:break;
        }
    }

    return temp;
}

double factor() {  //判断括号，计算括号内的内容
    double temp = 0;
    if (token == '(') {
        match('(');
        temp = exp();
        match(')');
    }else if (isdigit(token)){   //判断字符是否是阿拉伯数字，是则返回true
        //将读到的数字会退到输入流中
        ungetc(token, stdin);

        scanf("%lf", &temp);  //读取一个double的值

        token = getPrintableChar();  //读取一个字符并存储到token中
    }else{
        error();
    }

    return temp;
}

void error() {
    fprintf(stderr, "Error!\n");
    exit(EXIT_FAILURE);
}

void match(char expectedToken) {   //消耗不会被存入树中的括号，读取下一个字符
    if (expectedToken == token) {
        token = getPrintableChar();
    }else{
        error();
    }
}

char getPrintableChar() { //去除空字符，得到一个有效的字符
    char temp;

    do{
        temp = (char) getchar();
    } while (isblank(temp));

    return temp;
}
void untoken(char* a){
    int i=1;
    token= (char) getchar();
    a[0]=token;
    //printf("%c:%d\n",token,0);

    while (token!='\n'){
        token= (char) getchar();
        a[i]=token;
        //printf("%c:%d\n",token,i);
        i++;
    }
    i--;
    a[i]='\0';

    ungetc('\n',stdin);
    for (i--;i>=0;i--) {
        ungetc(a[i],stdin);
    }

}
