#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(){
    int server_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("0.0.0.0");
    server_addr.sin_port = htons(3884);

    bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr));

    listen(server_sock, 10);

    while(1){
        struct sockaddr_in client_addr;
        socklen_t client_size = sizeof(client_addr);
        int client_sock = accept(server_sock, (struct sockaddr*) &client_addr, &client_size);
        char str[] = "Hello World";
        write(client_sock, str, sizeof(str));
        close(client_sock);
    }

}
