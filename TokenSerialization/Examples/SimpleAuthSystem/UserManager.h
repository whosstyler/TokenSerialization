#pragma once
#include "../../TokenSerialization/Token.h"
#include <map>
#include <string>

class UserManager {
private:
    std::map<std::string, std::string> users;
    TokenSerialization tokenGenerator;

    std::map<std::string, std::string> loadUsersDB();
    void saveUserToDB(const std::string& username, const std::string& password);

public:
    UserManager();

    void registerUser(const std::string& username, const std::string& password);
    std::string loginUser(const std::string& username, const std::string& password);
    bool validateCredentials(const std::string& username, const std::string& password) const;
};
