// Example: Simple TCP client in C (connects to localhost:8080 and sends a message)
// Compile with: gcc -o tcp_client tcp_client.c
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main()
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        perror("connect");
        return 1;
    }
    char msg[] = "Hello, server!";
    send(sock, msg, strlen(msg), 0);
    close(sock);
    return 0;
}
