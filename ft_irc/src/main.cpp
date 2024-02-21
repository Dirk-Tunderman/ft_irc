// main.cpp
#include <iostream>
#include "server.hpp"

int main() {
    // Instantiate Server object with a specific port
    Server myServer(8080); // Specify the port explicitly

    // Call initialization method
    if (!myServer.initializeServer()) {
        std::cerr << "Failed to initialize server." << std::endl;
        return 1; // Return error code
    }

    return 0; // Successful execution
}