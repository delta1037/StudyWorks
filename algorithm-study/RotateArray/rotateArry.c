#include <stdio.h>
#define N 7
void reverse(int* arr,int left,int right){
	int t;
	while(left<right){
		t=arr[left];
		arr[left]=arr[right];
		arr[right]=t;

		left++;
		right--;
	}
}

int main(){
	int nums[N];
	int k;

	printf("enter %d numbers:\n",N);
	for(int i=0;i<N;i++){
		scanf("%d",&nums[i]);
	}

	printf("rotate k= ");
	scanf("%d",&k);
	k=k%N;
	k=N-k;

	reverse(nums,0,k-1);
	reverse(nums,k,N-1);
	reverse(nums,0,N-1);

	for(int i=0;i<N;i++){
		printf("%d  ",nums[i]);
	}

	return 0;
}