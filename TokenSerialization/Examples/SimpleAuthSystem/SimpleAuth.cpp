#include "UserManager.h"
#include <iostream>

#ifdef SIMPLE_AUTH_SYSTEM_EXAMPLE
int main2() {
    UserManager userManager;

    int choice;
    std::cout << "1. Register\n2. Login\nChoose an option: ";
    std::cin >> choice;

    std::string username, password;
    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;

    switch(choice) {
    case 1:
        userManager.registerUser(username, password);
        std::cout << "Successfully registered!\n";
        break;
    case 2:
    {
        std::string userToken = userManager.loginUser(username, password);
        if(!userToken.empty()) {
            std::cout << "Login successful! Your access token: " << userToken << "\n";
        }
        else {
            std::cout << "Invalid credentials!\n";
        }
        break;
    }
    default:
        std::cout << "Invalid option!\n";
        break;
    }

    return 0;
}
#endif