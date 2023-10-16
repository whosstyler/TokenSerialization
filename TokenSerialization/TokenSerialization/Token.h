#include <string>
#include <chrono>
#include <sstream>

class TokenSerialization {
private:
    const std::string secret;

    std::string generateSignature(const std::string& data) const;

    std::vector<std::string> splitString(const std::string& str, char delimiter) const {
        std::vector<std::string> tokens;
        std::string token;
        std::istringstream tokenStream(str);
        while(std::getline(tokenStream, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }

    std::string joinStrings(const std::vector<std::string>& parts, const std::string& delimiter) const {
        std::ostringstream joined;
        for(size_t i = 0; i < parts.size(); ++i) {
            joined << parts[i];
            if(i < parts.size() - 1) {  // Only add delimiter between parts, not at the end
                joined << delimiter;
            }
        }
        return joined.str();
    }

public:
    explicit TokenSerialization(const std::string& secretKey);

    std::string createToken(const std::string& header, const std::string& payload, const std::chrono::system_clock::time_point& expiration);

    bool validateToken(const std::string& token) const;
};
