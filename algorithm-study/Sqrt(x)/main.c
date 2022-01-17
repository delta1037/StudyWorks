#include <stdio.h>
#include <math.h>

int mySqrt(int x) {

    double result=x;
    double delta=0.0001;

    while(fabs(result*result-x)>delta){
        result=(result+x/result)/2;
    }

    return (int)result;
}
int main() {
    int result;
    result=mySqrt(1000);
    printf("%d",result);
    return 0;
}