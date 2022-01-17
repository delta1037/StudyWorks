#include <stdio.h>
#include <malloc.h>

#define M 6

#define N 5


int M_TO_TEN(char* in){
    int result=0;
    int i=0;
    while (in[i]!='\0'){
        result=result*M+in[i]-'0';
        i++;
    }
    return result;

}
char* TEN_TO_N(int ten){
    char* result=(char*)malloc(32*sizeof(char));
    int array[32]={0};
    int i=0;

    while(ten>=N){
        array[i]=ten%N;
        ten=ten/N;
        i++;
    }
    array[i]=ten;

    int t=0;
    while(i>=0){
        result[t]= (char) (array[i] + '0');
        i--;
        t++;
    }

    return result;
}


int main() {
    char* input;

    printf("输入一串数字：");
    scanf("%s",input);

    int result_TEN=M_TO_TEN(input);

    printf("%d\n",result_TEN);

    char* result_N=TEN_TO_N(result_TEN);

    printf("%s\n",result_N);

}