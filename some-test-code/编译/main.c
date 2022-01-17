#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <arpa/inet.h>
#include <netdb.h>

#define ICMP_SIZE (sizeof(struct icmp))
#define ICMP_ECHO 8
#define ICMP_ECHOREPLY 0
#define BUF_SIZE 1024
#define NUM   10    // 发送报文次数
pid_t pid;

// ICMP报文数据结构
struct icmp{
    unsigned char         type;      // 类型
    unsigned char         code;      // 代码
    unsigned short        checksum;  // 校验和
    unsigned short        id;        // 标识符
    unsigned short        sequence;  // 序号
    struct timeval        timestamp; // 时间戳
};

// IP首部数据结构
struct ip{
    unsigned char   hlen:4;       // 首部长度
    unsigned char   version:4;    // 版本
    unsigned char   tos;          // 服务类型
    unsigned short  len;          // 总长度
    unsigned short  id;           // 标识符
    unsigned short  offset;       // 标志和片偏移
    unsigned char   ttl;          // 生存时间
    unsigned char   protocol;     // 协议
    unsigned short  checksum;     // 校验和
    struct in_addr  ipsrc;        // 32位源ip地址
    struct in_addr  ipdst;        // 32位目的ip地址
};

void pack(struct icmp * icmp, int sequence);
int unpack(char * buf, int len, char * addr);
float timediff(struct timeval *begain, struct timeval *end);
unsigned short checkSum(unsigned short *addr,int len);

//buffer
char buf[BUF_SIZE] = {0};  //缓冲

int main(int argc,char *argv[]){
    struct sockaddr_in from;
    struct sockaddr_in to;

    int send=0;
    int received=0;

    struct hostent *host;
    struct icmp send_icmp;
    int fromlen=0;
    int socket_a;
    int i,n;
    in_addr_t in_addr;

    memset(&from,0, sizeof(struct sockaddr_in));
    memset(&to,0, sizeof(struct sockaddr_in));

    if(argc<2){
        printf("use: %s hostname/IP address\n",argv[0]);
        exit(1);
    }

    //生成原始套接字
    socket_a=socket(AF_INET,SOCK_RAW,IPPROTO_ICMP);
    if(socket_a==-1){
        printf("socket error");
        exit(1);
    }

    //设置目的信息
    to.sin_family=AF_INET;

    //ip与域名之间的转换
    if((in_addr=inet_addr(argv[1]))==INADDR_NONE){
        //域名
        if((host=gethostbyname(argv[1]))==NULL){
            printf("gethostname error");
            exit(1);
        }
        to.sin_addr=*(struct in_addr *)host->h_addr_list[0];

    }else{
        //ip
        to.sin_addr.s_addr=in_addr;
    }

    //输出域名ip信息
    printf("PING %s (%s):%d byte of data\n",argv[1],inet_ntoa(to.sin_addr),(int)ICMP_SIZE);


    //循环发送报文，接收报文
    for(i=0;i<NUM;i++){
        send++;  //发送次数加一

        memset(&send_icmp,0,ICMP_SIZE);

        //对将发送的icmp打包
        pack(&send_icmp,send);

        //发送
        n= (int) sendto(socket_a, &send_icmp, ICMP_SIZE, 0, (struct sockaddr*)&to, sizeof(to));
        if(n==-1){
            printf("sendto error");
            continue;
        }
	printf("%d\n",send_icmp.sequence);

        //接收
        n= (int) recvfrom(socket_a, buf, 0, BUF_SIZE, (struct sockaddr*)&from, (socklen_t *) &fromlen);
        
        if(n==-1){
            printf("recvfrom error");
        }else{
            received++; //接收次数
        }

        //解包
        if(unpack(buf,ICMP_SIZE,inet_ntoa(from.sin_addr))==-1){
            printf("unpack error");
        }

        sleep(1);
    }

    //输出统计信息
    printf("-------%s Ping 统计信息\n",argv[1]);
    printf("发送%d个包,收到%d个包,包丢失率%d%% \n",send,received,(send-received)/send*100);

    return 0;
}
void pack(struct icmp * icmp, int sequence){
    icmp->type = ICMP_ECHO;
    icmp->code = 0;
    icmp->checksum = 0;
    icmp->id = (unsigned short) pid;
    icmp->sequence = (unsigned short) sequence;
    gettimeofday(&icmp->timestamp, 0);
    icmp->checksum = checkSum((unsigned short *)icmp, ICMP_SIZE);
}
int unpack(char * buf, int len, char * addr){
    int ipheadlen;
    struct ip *ip;
    struct icmp *icmp;
    float rtt;          // 记录往返时间
    struct timeval end; // 记录接收报文的时间戳

    ip = (struct ip* )buf;

    // 计算ip首部长度，即ip首部的长度标识乘4
    ipheadlen = ip->hlen << 2;

    // 越过ip首部，指向ICMP报文
    icmp = (struct icmp* )(buf + ipheadlen);

    // ICMP报文的总长度
    len -= ipheadlen;

    // 如果小于ICMP报文首部长度8
    if(len < 8){
        printf("ICMP packets\'s length is less than 8 \n");
        return -1;
    }

    // 确保是我们所发的ICMP_ECHO回应
    if(icmp->type != ICMP_ECHOREPLY || icmp->id != pid){
        printf("ICMP packets are not send by us \n");
        return -1;
    }

    // 计算往返时间
    gettimeofday(&end, 0);  //回来的时间
    rtt = timediff(&icmp->timestamp, &end);  //计算总时间

    // 打印ttl，rtt，seq
    printf("%d bytes from %s : icmp_seq=%u ttl=%d time=%fms \n", len, addr, icmp->sequence, ip->ttl, rtt);

    return 0;
}

//计算时间差
float timediff(struct timeval *begain, struct timeval *end){
    return ((end->tv_sec - begain->tv_sec)*1000 + (end->tv_usec - begain->tv_usec)/1000);
}

//计算校验和
unsigned short checkSum(unsigned short *addr,int len){
    unsigned int sum=0;
    while (len>1){
        sum+=*addr++;
        len-=2;
    }

    //处理剩下的一个字节
    if(len==1){
        sum+=*(unsigned char*)addr;
    }

    sum=(sum>>16)+(sum& 0xffff);
    sum+=(sum>>16);

    return (unsigned short)~sum;
}
