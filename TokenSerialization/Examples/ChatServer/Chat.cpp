#include "ChatServer.h"

#ifdef CHAT_SERVER_EXAMPLE
int main() {
    ChatServer server;

    // Simulate registering two users.
    std::string aliceToken = server.registerUser("Tyler", "password123");
    std::string bobToken = server.registerUser("Chris", "securePassword");

    // Both try to join the chat.
    if(server.joinChat("Tyler", aliceToken)) {
        std::cout << "Tyler joined the chat.\n";
    }

    if(server.joinChat("Chris", bobToken)) {
        std::cout << "Chris joined the chat.\n";
    }

    // Display active users.
    server.displayActiveUsers();

    return 0;
}
#endif