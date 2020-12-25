
//
// Created by Luka Mitrović on 25/12/2020.
//
#include "Client.h"
#include <iostream>


Client::Client (){
    char buffer[1024] = "Hello from client";
    connectToServer(SERVERIP,SERVERPORT);
    sendMessage(serverSocket, buffer);
}

void Client::connectToServer(const char *serverIP, int port){
    serverSocket = socket(AF_INET,SOCK_STREAM, 0);

    addr.sin_addr.s_addr = inet_addr(serverIP);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(SERVERPORT);

    if(connect(serverSocket,(struct sockaddr*)&addr, sizeof(addr)) == 0){
        cout << "Sucessful connection to server " << serverIP << endl;
    }
    else {
        cout << "Connection refused! " << endl;
    }


    }
void Client::sendMessage(int serverSocket, char *buffer) {
    send(serverSocket, buffer , sizeof(buffer),0);
    cout << "Message was sent!" << endl;
    buffer = {""};
    recv(serverSocket, buffer, sizeof (buffer),0);
    cout << buffer << endl;
}