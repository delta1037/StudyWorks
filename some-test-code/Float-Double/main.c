#include <stdio.h>

int main() {
    int a0;
    double h0;
    scanf("%d",&a0);
    scanf("%lf",&h0);
    printf("%lf",a0/(h0*h0));

    printf("\n\n");

    int a1;
    int h1;
    scanf("%d",&a1);
    scanf("%d",&h1);
    printf("%d",a1/(h1*h1));

    printf("\n\n");

    double a2;
    double h2;
    scanf("%f",&a2);
    scanf("%f",&h2);
    printf("%f",a2/(h2*h2));

    printf("\n\n");

    double a;
    double h;
    scanf("%lf",&a);
    scanf("%lf",&h);
    printf("%lf",a/(h*h));

    return 0;
}