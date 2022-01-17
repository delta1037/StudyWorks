//test.c
#include <stdio.h>

int add(int x1,int y1){
  return x1+y1;  //返回x1和y1的值
}

void main(){
  //定义一系列的变量并赋值
  int x=3;
  int y=1;
  int result;

  result = add(x,y);  //调用add函数，用result接收返回值
  printf("%d\n",result);   //输出返回值到屏幕
}
