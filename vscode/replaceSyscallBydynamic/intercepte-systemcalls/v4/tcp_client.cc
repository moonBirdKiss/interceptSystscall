#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main(){
    int client_sock = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    memset(&server_addr, 0 ,sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(3884);
    connect(client_sock, (struct sockaddr*)&server_addr, sizeof(server_addr));
    char buf[40] = "hello World";
    read(client_sock, buf, sizeof(buf)-1);
    printf("Msg: %s\n", buf);
    close(client_sock);
    return 0;
}
