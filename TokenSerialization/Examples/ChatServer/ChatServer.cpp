#include "ChatServer.h"

ChatServer::ChatServer() : tokenHandler("SuperSecretKeyForChat") {}

std::string ChatServer::registerUser(const std::string& username, const std::string& password) {
    registeredUsers[username] = User(username, password);
    return tokenHandler.createToken("ChatUser", username, std::chrono::system_clock::now() + std::chrono::hours(24));
}

bool ChatServer::joinChat(const std::string& username, const std::string& token) {
    if(registeredUsers.find(username) == registeredUsers.end()) {
        return false;  // User not registered.
    }

    if(!tokenHandler.validateToken(token)) {
        return false;  // Token is invalid or expired.
    }

    activeUsers.insert(username);
    return true;
}

void ChatServer::displayActiveUsers() const {
    std::cout << "Active users in chat:\n";
    for(const auto& user : activeUsers) {
        std::cout << "- " << user << "\n";
    }
}
