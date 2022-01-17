//
// Created by delta on 19-7-10.
//

#ifndef SOCKET_C___SOCKET_H
#define SOCKET_C___SOCKET_H

#include <cstring>
#include <stdint-gcc.h>
#include <netinet/in.h>
#include <bits/socket_type.h>

#include "../include/data.h"

using namespace std;
class MSG{

};

class socketServer{
    uint8_t initServer();

private:
    int server_sock;
    struct  sockaddr_in server_addr;
};

class socketClient{

};
#endif //SOCKET_C___SOCKET_H
