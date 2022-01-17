#include <stdio.h>

int re(int c,int d);

int re(int c,int d){
	return c+d;
}

int main(){
	int a=1;
	int b=2;
	
	int d;
	
	d=re(1,2);

	printf("%d",d);
}
	
