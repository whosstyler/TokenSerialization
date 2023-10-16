#include "UserManager.h"
#include <fstream>
#include <iostream>

UserManager::UserManager() : tokenGenerator("SuperSecretKey123") {
    users = loadUsersDB();
}

std::map<std::string, std::string> UserManager::loadUsersDB() {
    std::map<std::string, std::string> loadedUsers;
    std::ifstream db("users_db.txt");
    std::string username, password;
    while(db >> username >> password) {
        loadedUsers[username] = password;
    }
    return loadedUsers;
}

void UserManager::saveUserToDB(const std::string& username, const std::string& password) {
    std::ofstream db("users_db.txt", std::ios_base::app);
    db << username << " " << password << std::endl;
}

void UserManager::registerUser(const std::string& username, const std::string& password) {
    users[username] = password;
    saveUserToDB(username, password);
}

std::string UserManager::loginUser(const std::string& username, const std::string& password) {
    if(!validateCredentials(username, password)) {
        return "";
    }
    auto expiration = std::chrono::system_clock::now() + std::chrono::hours(1);
    return tokenGenerator.createToken("authUser", username, expiration);
}

bool UserManager::validateCredentials(const std::string& username, const std::string& password) const {
    return !(users.find(username) == users.end() || users.at(username) != password);
}
