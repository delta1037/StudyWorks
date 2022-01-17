#include <stdio.h>

int main(){
	
        #pragma omp parallel
	{
		printf("hellow\n");
	}

	printf("hellow boy\n");
	return 0;

}
