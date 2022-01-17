//
// Created by delta on 19-7-10.
//
#include "../include/socket.h"

uint8_t socketServer::initServer(){
    // init socket fd
    server_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    // init socket addr struct
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    return SUCCESS;
}