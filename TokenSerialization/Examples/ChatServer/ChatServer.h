#pragma once
#include "../../TokenSerialization/Token.h"
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <iostream>

class User {
public:
    std::string username;
    std::string password;

    User() = default;
    User(const std::string& user, const std::string& pass)
        : username(user), password(pass) {}
};

class ChatServer {
private:
    TokenSerialization tokenHandler;
    std::unordered_map<std::string, User> registeredUsers;
    std::unordered_set<std::string> activeUsers;

public:
    ChatServer();

    std::string registerUser(const std::string& username, const std::string& password);
    bool joinChat(const std::string& username, const std::string& token);
    void displayActiveUsers() const;
};
