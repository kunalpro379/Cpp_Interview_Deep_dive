#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_fd, (sockaddr*)&addr, sizeof(addr));
    listen(server_fd, 5);

    std::cout << "Server listening on port 8080\n";

    int client_fd = accept(server_fd, nullptr, nullptr);

    char buffer[1024];

    int bytes_read = read(client_fd, buffer, sizeof(buffer) - 1);

    if (bytes_read > 0) {
        buffer[bytes_read] = '\0'; 
        std::cout << "Client says: " << buffer << std::endl;
    }

    const char* reply = "Hello from server";
    write(client_fd, reply, strlen(reply));

    close(client_fd);
    close(server_fd);
}