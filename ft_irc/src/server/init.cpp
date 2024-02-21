#include "../inc/server.hpp"

Server::Server(int p) : port(p), isRunning(false) {
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        std::cerr << "Socket creation failed." << std::endl;
    }
}

Server::~Server() {
    if (isRunning) {
        close(server_fd);
    }
}

bool Server::initializeServer() {
    if (server_fd == -1) return false;

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    memset(&address.sin_zero, 0, sizeof(address.sin_zero));

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        std::cerr << "Bind failed." << std::endl;
        return false;
    }

    if (listen(server_fd, 10) < 0) {
        std::cerr << "Listen failed." << std::endl;
        return false;
    }

    isRunning = true;
    std::cout << "Server initialized and listening on port " << port << std::endl;
    return true;
}

// In your Server class, add methods for setting non-blocking mode and handling poll
bool Server::setNonBlocking(int sockfd) {
    int flags = fcntl(sockfd, F_GETFL, 0);
    if (flags == -1) return false;
    return fcntl(sockfd, F_SETFL, flags | O_NONBLOCK) != -1;
}

void Server::run() {
    struct pollfd fds[MaxClients + 1]; // +1 for the server socket
    int nfds = 1;

    // Initialize server socket in fds[0]
    fds[0].fd = server_fd;
    fds[0].events = POLLIN;

    // Server loop
    while (isRunning) {
        int poll_count = poll(fds, nfds, Timeout); // Timeout as needed

        if (poll_count < 0) {
            std::cerr << "Poll error." << std::endl;
            break;
        }

        if (poll_count == 0) {
            // Handle timeout
            continue;
        }

        // Handle incoming connections and I/O on client sockets
    }
}


// Listen for incoming connections
if (listen(server_fd, BACKLOG) < 0) {
    std::cerr << "Listen failed." << std::endl;
    return false; // Return false to indicate error
}

std::cout << "Server listening on port " << port << std::endl;