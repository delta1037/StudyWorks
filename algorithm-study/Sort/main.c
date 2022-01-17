#include <stdio.h>

void QuickSort(int* arr,int left,int right);
int partion(int* arr,int left,int right);

void SelectSort(int* arr,int length);

void InsertSort(int* arr,int length);

void HeapSort(int* arr,int length);
void min_HeapSort(int* arr,int left,int right);

int main() {
    int arr[20];

    for(int i=0;i<20;i++){
        arr[i]=20-i;
    }
    printf("快速排序:\n");
    for(int i=0;i<20;i++){
        printf(" %d",arr[i]);
    }
    QuickSort(arr,0,19);
    for(int i=0;i<20;i++){
        printf(" %d",arr[i]);
    }
    printf("\n");

    for(int i=0;i<20;i++){
        arr[i]=20-i;
    }
    printf("插入排序:\n");
    for(int i=0;i<20;i++){
        printf(" %d",arr[i]);
    }
    InsertSort(arr,20);
    for(int i=0;i<20;i++){
        printf(" %d",arr[i]);
    }
    printf("\n");

    for(int i=0;i<20;i++){
        arr[i]=20-i;
    }
    printf("选择排序:\n");
    for(int i=0;i<20;i++){
        printf(" %d",arr[i]);
    }
    SelectSort(arr,20);
    for(int i=0;i<20;i++){
        printf(" %d",arr[i]);
    }
    printf("\n");

    for(int i=0;i<20;i++){
        arr[i]=20-i;
    }
    printf("堆排序:\n");
    for(int i=0;i<20;i++){
        printf(" %d",arr[i]);
    }
    HeapSort(arr,20);
    for(int i=0;i<20;i++){
        printf(" %d",arr[i]);
    }



    return 0;
}

//快速排序

void QuickSort(int* arr,int left,int right){
    int result;

    result=partion(arr,left,right);

    if((result-1)>left){
        QuickSort(arr,left,result-1);
    }
    if((result+1)<right){
        QuickSort(arr,result+1,right);
    }

}
int partion(int* arr,int left,int right){

    int biao=arr[left];
    int z=left;
    int b=1;
    while(left!=right){
        if(b==1){
            while(arr[right]>=biao&&right>left){
                right--;
            }
            arr[z]=arr[right];
            z=right;
            b=0;
        }
        else{
            while(arr[left]<=biao&&left<right){
                left++;
            }
            arr[z]=arr[left];
            z=left;
            b=1;
        }
    }
    arr[left]=biao;
    return left;
}
//插入排序
void InsertSort(int* arr,int length){
    int temp;
    int i,j;
    for(i=1;i<length;i++){
        j=i;
        for(;arr[j]<arr[j-1];j--){
            temp=arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=temp;
        }
    }
}
// 选择排序
void SelectSort(int* arr,int length){
    int i,j,min,temp;
    for(i=0;i<length;i++){
        min=i;
        for(j=i+1;j<length;j++){
            if(arr[min]>arr[j]){
                min=j;
            }
        }
        temp=arr[min];
        arr[min]=arr[i];
        arr[i]=temp;
    }
}
//堆排序
void HeapSort(int* arr,int length){
    int i;
    int temp;
    for(i=length/2-1;i>=0;i--){
        min_HeapSort(arr,i,length-1);
    }

    for(i=length-1;i>0;i--){
        temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;

        min_HeapSort(arr,0,i-1);
    }
}
void min_HeapSort(int* arr,int left,int right){
    int temp;
    int dad=left;
    int son=dad*2+1;

    while (son<right){
        if(son+1<right&&arr[son]<arr[son+1]){
            son++;
        }

        if(arr[dad]<arr[son]){
            temp=arr[son];
            arr[son]=arr[dad];
            arr[dad]=temp;

            dad=son;
            son=dad*2;
        } else{
            dad=son;
            son=dad*2;
        }
    }
}