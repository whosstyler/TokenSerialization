# TokenSerialization

TokenSerialization is a C++ project inspired by JSON Web Tokens (JWT). It provides a way to generate and validate tokens with a focus on security using HMAC with SHA-256.


## Why TokenSerialization is Useful for C++ Projects

Tokens play an indispensable role in ensuring security and user authentication in modern web applications and services. While many web-based platforms have out-of-the-box solutions for token generation and validation, C++ projects, particularly those operating in backend server-side roles, might not have direct access to such high-level tools. Here are a few reasons why TokenSerialization is valuable:

1. **Seamless Integration:** Written natively in C++, TokenSerialization is designed for optimal performance and easy integration into existing C++ codebases without the need for wrapping other languages or using bindings.

2. **Security:** By employing HMAC with SHA-256, TokenSerialization provides robust security against tampering. This cryptographic approach ensures that if someone tries to alter the token data, it would invalidate the signature, making the token useless.

3. **Stateless Authentication:** In distributed systems or microservices architecture, keeping track of user sessions can be challenging. Using tokens like those generated by TokenSerialization can enable stateless authentication, where each request from a client carries all the information needed to authenticate the user, eliminating the need for sessions.

4. **Flexibility:** The clear separation of headers, payloads, and cryptographic signatures allows developers to customize their tokens. This means that apart from authentication, tokens can be used for carrying user roles, permissions, or even application-specific data.

5. **Expiration Handling:** A built-in expiration mechanism ensures tokens are not valid indefinitely. This minimizes risks associated with token leaks, as even if malicious actors get a hold of a token, they have a limited timeframe to use it.

6. **Unified Toolset:** C++ projects might interact with databases, external APIs, or other systems where varying token mechanisms are in play. Having a standardized, secure, and efficient method to generate and validate tokens simplifies development and maintenance.

7. **Examples and Community:** With example projects provided, developers can quickly grasp the implementation and use cases. Moreover, as an open-source project, TokenSerialization encourages community contributions, ensuring constant updates and improvements.

TokenSerialization brings the power and simplicity of JWT-like tokens to C++ developers, allowing them to build more secure and scalable applications with ease.

## Features

- **Secure Token Generation:** Create tokens using HMAC with SHA-256.
- **Expiration:** Set an expiration date on tokens.
- **Validation:** Validate tokens based on their signature and expiration.
- **Utility Functions:** Helper methods for string manipulation and token handling.

## Getting Started

### Prerequisites

- OpenSSL library installed.

### Installation

1. Clone the repository:
   ```
   git clone https://github.com/whosstyler/TokenSerialization.git
   ```

2. Navigate to the project directory and build the project.

### Usage

The primary class is `TokenSerialization`. Below are the main functionalities:

1. **Initialization**
   ```cpp
   TokenSerialization tokenSerialization("your_secret_key_here");
   ```

2. **Create a Token**
   ```cpp
   std::string token = tokenSerialization.createToken("header_here", "payload_here", expiration_time_point);
   ```

3. **Validate a Token**
   ```cpp
   bool isValid = tokenSerialization.validateToken(token);
   ```

## Example Projects

There are two example projects included to showcase the capabilities of the TokenSerialization library:

1. **Chat Server**
- [Click Me](./TokenSerialization/Examples/ChatServer)

2. **Simple Authentication System**
- [Click Me](./TokenSerialization/Examples/SimpleAuthSystem)

Navigate to the respective directories to explore and run the examples.

## Contributing

If you'd like to contribute, please fork the repository and use a feature branch. Pull requests are warmly welcome.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.

## Acknowledgements

- Thanks to the OpenSSL project for the crypto libraries.

---