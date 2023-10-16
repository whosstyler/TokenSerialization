#include "Token.h"
#include <openssl/evp.h>
#include <openssl/hmac.h>

TokenSerialization::TokenSerialization(const std::string& secretKey)
    : secret(secretKey)
{}

std::string TokenSerialization::generateSignature(const std::string& data) const {
    unsigned int len = EVP_MAX_MD_SIZE;
    unsigned char result[EVP_MAX_MD_SIZE];

    HMAC(
        EVP_sha256(),
        secret.c_str(), secret.size(),
        reinterpret_cast<const unsigned char*>(data.c_str()), data.size(),
        result, &len
    );

    return {result, result + len};
}

std::string TokenSerialization::createToken(
    const std::string& header,
    const std::string& payload,
    const std::chrono::system_clock::time_point& expiration)
{
    const auto expirationTimeT = std::chrono::system_clock::to_time_t(expiration);
    const std::vector<std::string> parts = {header, payload, std::to_string(expirationTimeT)};
    const std::string tokenData = joinStrings(parts, ".");
    const std::string signature = generateSignature(tokenData);

    return tokenData + "." + signature;
}

bool TokenSerialization::validateToken(const std::string& token) const {
    const auto parts = splitString(token, '.');

    if(parts.size() != 4) {  // Expecting header, payload, expiration, signature
        return false;
    }

    const std::string headerPayloadExpiration = parts[0] + "." + parts[1] + "." + parts[2];
    const std::string receivedSignature = parts[3];
    const std::time_t expirationTimeT = std::stoll(parts[2]);
    const auto expiration = std::chrono::system_clock::from_time_t(expirationTimeT);

    if(expiration < std::chrono::system_clock::now()) {
        return false;  // Token has expired.
    }

    const std::string computedSignature = generateSignature(headerPayloadExpiration);

    return receivedSignature == computedSignature;
}