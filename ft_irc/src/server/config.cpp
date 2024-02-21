#include <fcntl.h> // For fcntl()
#include <vector>
#include <poll.h>

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
