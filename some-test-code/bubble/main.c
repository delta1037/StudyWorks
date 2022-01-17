#include <stdio.h>
#include <string.h>
#include <malloc.h>

void bubble_sort(int* num,int n){

	int i, j, temp;
	for (j = 0; j < n - 1; j++){
		for (i = 0; i < n - 1 ; i++){
			if (num[i] > num[i+1]){
				temp = num[i];
				num[i] = num[i+1];
				num[i+1] = temp;
			}
		}
	}
	for (i = 0; i <= n - 1; i++){
		printf("%d ",num[i]);
	}
	printf("\n");
}
void bubble_sort1(int* num,int n){

    int i, j, temp;
    for (i = 0; i < n - 1; i++){
        for (j = i+1; j < n ; j++){
            if (num[i] > num[j]){
                temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
    }
    for (i = 0; i <= n - 1; i++){
        printf("%d ",num[i]);
    }
    printf("\n");
}
void bubble_sort2(int* num,int n){

    int i, j, temp;
    for (i = 0; i < n - 1; i++){
        for (j = 0; j < n-i-1 ; j++){
            if (num[j] > num[j+1]){
                temp = num[j];
                num[j] = num[j+1];
                num[j+1] = temp;
            }
        }
    }
    for (i = 0; i <= n - 1; i++){
        printf("%d ",num[i]);
    }
    printf("\n");
}
void bubble_sort3(int* num,int n){

    int i, j, temp;
    for (i = 0; i < n - 1; i++){
        for (j = 0; j < n-i-2 ; j++){
            if (num[j] > num[n-i-1]){
                temp = num[j];
                num[j] = num[n-i-1];
                num[n-i-1] = temp;
            }
        }
    }
    for (i = 0; i <= n - 1; i++){
        printf("%d ",num[i]);
    }
    printf("\n");
}

//reduce exchange
void bubble_sort1_1(int* num,int n){

    int i, j, temp;
    int index;
    for (i = 0; i < n - 1; i++){
        index=i;
        for (j = i+1; j < n ; j++){
            if (num[index] > num[j]){
                index=j;
            }
        }
        if(index!=i){
            temp=num[i];
            num[i]=num[index];
            num[index]=temp;
        }
    }
    for (i = 0; i <= n - 1; i++){
        printf("%d ",num[i]);
    }
    printf("\n");
}
void bubble_sort3_1(int* num,int n){

    int i, j, temp;
    int index;
    for (i = 0; i < n - 1; i++){
        index=n-i-1;
        for (j = 0; j < n-i-2 ; j++){
            if (num[index] < num[j]){
                index=j;
            }
        }
        if(index!=(n-i-1)){
            temp=num[n-i-1];
            num[n-i-1]=num[index];
            num[index]=temp;
        }
    }
    for (i = 0; i <= n - 1; i++){
        printf("%d ",num[i]);
    }
    printf("\n");
}
int main() {
    printf("print ten numbers:\n");
    int num[10];

    for(int i=0;i<10;i++){
        scanf("%d",&num[i]);
    }
    bubble_sort(num,10);
    printf("\n\n");
    bubble_sort1(num,10);
    printf("\n\n");
    bubble_sort2(num,10);
    printf("\n\n");
    bubble_sort3(num,10);
    printf("\n\n");
    bubble_sort1_1(num,10);
    printf("\n\n");
    bubble_sort3_1(num,10);
    return 0;
}