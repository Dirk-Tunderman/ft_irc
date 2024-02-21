#ifndef SERVER_HPP
#define SERVER_HPP

#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include <iostream>
#include <fcntl.h> // For fcntl()
#include <vector>
#include <poll.h>

class Server {
    private:
        int server_fd;
        struct sockaddr_in address;
        int port;
        bool isRunning;

    public:
        Server(int port);
        ~Server();
        bool initializeServer();
};

#endif
