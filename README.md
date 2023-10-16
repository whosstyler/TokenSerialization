# TokenSerialization

TokenSerialization is a C++ project inspired by JSON Web Tokens (JWT). It provides a way to generate and validate tokens with a focus on security using HMAC with SHA-256.

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