
......
extern int printf (const char *__restrict __format, ...);
......
extern int scanf (const char *__restrict __format, ...) ;
......

# 944 "/usr/include/stdio.h" 3 4
# 3 "test.c" 2
# 4 "test.c"
int add(int x1,int y1){
  return x1+y1;
}

void main(){
  int x=3;
  int y=1;
  int result;

  result = add(x,y);
  printf("%d\n",result);
}
