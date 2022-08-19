#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

int main() {
    int socket_desc;
    struct sockaddr_in server;
    char *message, server_reply[20000];
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket!\n");
     }
    server.sin_add.s_addr = inet_addr("IP");
    server.sin_family = AF_INET;
    server.sin_port = htons(80);
    if(connect(socket_desc, (struct sockeaddr *)&server, sizeof(server)) < 0) {
        printf("Connect error!\n");
        return 1;
    }
    message = "GET /HTTP/1.1\r\nHPST: Site \r\n\r\n";
    if(send(socket_desc, message, strlen(message), 0) < 0) {
        return 1;
    }
    if(recv(socket_desc, server_reply, 20000, 0) < 0) {
        printf("Recv Failed!\n");
        return 1;
    }

    printf("\n%s\n", server_reply);
    return 0;
}