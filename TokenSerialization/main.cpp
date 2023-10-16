#include "TokenSerialization/Token.h"
#include <iostream>

// Define only one of the following at a time
// #define CHAT_SERVER_EXAMPLE
// #define SIMPLE_AUTH_SYSTEM_EXAMPLE
 #define LIBRARY_MAIN

#ifdef LIBRARY_MAIN
int main()
{
    TokenSerialization tokenGen("sampleSecret");

    auto expiration_time = std::chrono::system_clock::now() + std::chrono::hours(1);  // 1 hour from now
    std::string token = tokenGen.createToken("sampleHeader", "samplePayload", expiration_time);
    std::cout << "Generated Token: " << token << std::endl;

    bool isValid = tokenGen.validateToken(token);
    std::cout << "Token is valid: " << isValid << std::endl;

    return 0;
}
#endif