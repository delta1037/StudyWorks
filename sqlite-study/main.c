#include  <sqlite3.h>
#include <stdio.h>
#include <string.h>

sqlite3 *db=NULL;
char *zErrMsg=NULL;
int ret=0;


static int callback(void *NotUsed,int argc,char **argv,char **azColName){
    int i;
    for(i=0;i<argc;i++){
        printf("%s=%s\n",azColName[i],argv[i]? argv[i]:NULL);
    }
    printf("\n");
    return 0;
}

void student_hub();
void sqlite_init();
void sqlite_add();
void sqlite_delete();
void sqlite_select();
void sqlite_change();

int main() {
    printf("          欢迎使用学生成绩管理系统!\n\n");
    printf("Copyright © 2017 liubo All Rights Reserved\n\n");
    student_hub();
    return 0;
}
void student_hub(){
    //学生成绩信息管理系统

    /**
     * 其中表单和数据已经初始化,所以会出现以下错误:
     * SQL error:table STUDENT already exists
     *SQL error:UNIQUE constraint failed: STUDENT.ID
     */
    char j[5];
    printf("请根据实际情况决定是否要初始化,确定初始化输入yes,不初始化输入no\n");
    scanf("%s",j);

    if(strcmp(j,"yes") == 0){
        sqlite_init();
    }

    //输出命令提示
    printf("数据添加命令:add\n 数据删除命令:delete\n 数据查看命令:select\n 数据更改命令:change\n 退出命令:exit\n");
    //s存储用户输入的字符串
    char s[10];
    scanf("%s",s);

    //输出提示指令,输入指令,在输入exit之前 ,进行循环操作
    while(strcmp(s,"exit") != 0){

        if(strcmp(s,"add") == 0){
            sqlite_add();
        }else if (strcmp(s,"delete") == 0){
            sqlite_delete();
        }else if (strcmp(s,"select") == 0){
            sqlite_select();
        }else if (strcmp(s,"change") == 0){
            sqlite_change();
        }else{
            printf("该命令不存在,请重新输入\n");
        }
        scanf("%s",s);
    }

    sqlite3_close(db);
    //关闭数据库

}
void sqlite_init(){
    //数据库首次初始化
    //连接到现有的数据库,如果不存在它将会被创建
    ret=sqlite3_open("student.db",&db);

    //创建表单
    char* sql=NULL;
    sql = "CREATE TABLE STUDENT("  \
         "ID INT PRIMARY KEY     NOT NULL," \
         "NAME           TEXT    NOT NULL," \
         "SCORE          INT     );";
    ret =sqlite3_exec(db,sql,callback,0,&zErrMsg);

    if(ret!=SQLITE_OK){
        fprintf(stderr,"SQL error:%s\n",zErrMsg);
        sqlite3_free(zErrMsg);
    }else{
        fprintf(stdout,"表单创建成功\n");
    }

    //创建初始化记录
    sql = "INSERT INTO STUDENT (ID,NAME,SCORE) "  \
         "VALUES (1, 'Panel', 99 ); " \
         "INSERT INTO STUDENT (ID,NAME,SCORE) "  \
         "VALUES (2, 'Allen', 100); "     \
         "INSERT INTO STUDENT (ID,NAME,SCORE)" \
         "VALUES (3, 'Teddy', 97 );" \
         "INSERT INTO STUDENT (ID,NAME,SCORE)" \
         "VALUES (4, 'Mark',94 );";

    ret =sqlite3_exec(db,sql,callback,0,&zErrMsg);
    if(ret!=SQLITE_OK){
        fprintf(stderr,"SQL error:%s\n",zErrMsg);
        sqlite3_free(zErrMsg);
    }else{
        fprintf(stdout,"数据初始化成功\n");
    }
    //关闭数据库
    sqlite3_close(db);

}
void sqlite_add(){
    //数据库添加记录
    //ID NAME SCORE
    int  ID=0;
    char name[50];
    int score=0;
    ret=sqlite3_open("student.db",&db);

    printf("请依次按照提示输入ID,name,score\n");

    printf("输入ID:\n");
    scanf("%d",&ID);
    printf("输入名字:\n");
    scanf("%s",name);
    printf("输入score:\n");
    scanf("%d",&score);

    char *sql = sqlite3_mprintf("INSERT INTO STUDENT (ID,NAME,SCORE) VALUES(%d,%Q,%d);",ID,name,score);


    ret =sqlite3_exec(db,sql,0,0,&zErrMsg);

    if(ret!=SQLITE_OK){
        fprintf(stderr,"SQL error:%s\n",zErrMsg);
        sqlite3_free(zErrMsg);
    }else{
        fprintf(stdout,"数据插入成功\n");
    }

    //释放内存病关闭数据库
    sqlite3_free(sql);
    sqlite3_close(db);

}
void sqlite_delete(){
    //删除记录
    ret=sqlite3_open("student.db",&db);
    printf("请输入要删除的ID");
    int ID=0;

    scanf("%d", &ID);

    char *sql= sqlite3_mprintf("DELETE from STUDENT where ID=%d ;" \
            "SELECT * from STUDENT",ID);

    ret =sqlite3_exec(db,sql,callback,0,&zErrMsg);

    if(ret!=SQLITE_OK){
        fprintf(stderr,"SQL error:%s\n",zErrMsg);
        sqlite3_free(zErrMsg);
    }else{
        fprintf(stdout,"数据删除成功\n");
    }

    //释放内存病关闭数据库
    sqlite3_free(sql);
    sqlite3_close(db);
}
void sqlite_select(){
    //数据库查找操作
    ret=sqlite3_open("student.db",&db);

    char* sql = "SELECT * from STUDENT";
    ret = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

    if(ret!=SQLITE_OK){
        fprintf(stderr,"SQL error:%s\n",zErrMsg);
        sqlite3_free(zErrMsg);
    }else{
        fprintf(stdout,"数据读取完毕\n");
    }

    //关闭数据库
    sqlite3_close(db);
}
void sqlite_change(){
    //更改记录
    ret=sqlite3_open("student.db",&db);

    int ID=0;
    int score=0;
    printf("输入你想要更改的ID: ");
    scanf("%d",&ID);
    printf("输入%d的成绩: ",ID);
    scanf("%d",&score);

    char* sql=NULL;
    sql = sqlite3_mprintf("UPDATE STUDENT set SCORE = %d where ID=%d; " \
         "SELECT * from STUDENT",score,ID);

    ret = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

    if(ret!=SQLITE_OK){
        fprintf(stderr,"SQL error:%s\n",zErrMsg);
        sqlite3_free(zErrMsg);
    }else{
        fprintf(stdout,"数据更改完毕\n");
    }

    //释放内存病关闭数据库
    sqlite3_free(sql);
    sqlite3_close(db);
}

