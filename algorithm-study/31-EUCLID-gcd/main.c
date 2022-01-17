#include <stdio.h>

int EXCLUID(int a,int b){
    if(b==0){
        return a;
    }else{
        return EXCLUID(b,a%b);
    }
}
int main() {
    int result;
    result=EXCLUID(30,21);
    printf("%d",result);
    return 0;
}