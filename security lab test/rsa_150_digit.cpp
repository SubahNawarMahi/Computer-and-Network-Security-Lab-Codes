#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdint>
using namespace std;
// Pre-generated 150-digit prime numbers p and q
const std::string p_str = "123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123457";
const std::string q_str = "987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210987651";

// Convert a string representation of a large number to an integer vector
std::vector<uint8_t> stringToVector(const std::string& str) {
    std::vector<uint8_t> result;
    for (char c : str) {
        result.push_back(c - '0');
    }
    return result;
}

// Convert an integer vector to a string representation of a large number
std::string vectorToString(const std::vector<uint8_t>& vec) {
    std::string result;
    for (uint8_t digit : vec) {
        result += (digit + '0');
    }
    return result;
}

// Modular exponentiation: (base ^ exponent) % modulus
uint64_t modPow(uint64_t base, uint64_t exponent, uint64_t modulus) {
    uint64_t result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent >>= 1;
    }
    return result;
}

// Encrypt a message using RSA algorithm
std::string rsaEncrypt(const std::string& message, const std::vector<uint8_t>& publicKey) {
    std::vector<uint8_t> ciphertext;
    for (char c : message) {
        uint64_t m = c;
        uint64_t e = 0;
        for (uint8_t digit : publicKey) {
            e = e * 10 + digit;
        }
        uint64_t n = 0;
        for (uint8_t digit : publicKey) {
            n = n * 10 + digit;
        }
        //uint64_t
        c = modPow(m, e, n);
        while (c > 0) {
            ciphertext.insert(ciphertext.begin(), c % 10);
            c /= 10;
        }
    }
    return vectorToString(ciphertext);
}

// Decrypt a ciphertext using RSA algorithm
std::string rsaDecrypt(const std::string& ciphertext, const std::vector<uint8_t>& privateKey) {
    std::vector<uint8_t> decryptedText;
    for (size_t i = 0; i < ciphertext.length(); i += 150) {
        std::string block = ciphertext.substr(i, 150);
        uint64_t c = 0;
        for (char digit : block) {
            c = c * 10 + (digit - '0');
        }
        uint64_t d = 0;
        for (uint8_t digit : privateKey) {
            d = d * 10 + digit;
        }
        uint64_t n = 0;
        for (uint8_t digit : privateKey) {
            n = n * 10 + digit;
        }
        uint64_t m = modPow(c, d, n);
        while (m > 0) {
            decryptedText.insert(decryptedText.begin(), m % 10);
            m /= 10;
        }
    }
    return vectorToString(decryptedText);
}

int main() {
    // Convert prime numbers p and q to integer vectors
    std::vector<uint8_t> p = stringToVector(p_str);
    std::vector<uint8_t> q = stringToVector(q_str);

    // Concatenate p and q to form the RSA modulus n
    std::vector<uint8_t> n = p;
    n.insert(n.end(), q.begin(), q.end());

    // Generate the public and private keys
    std::vector<uint8_t> publicKey = {1, 3, 7};  // Example public key
    std::vector<uint8_t> privateKey = {9, 7, 3}; // Example private key

    // Message to be encrypted
    std::string message ;//= "Hello, RSA!";
cin>>message;
    // Encrypt the message
    std::string ciphertext = rsaEncrypt(message, publicKey);
    std::cout << "Ciphertext: " << ciphertext << std::endl;

    // Decrypt the ciphertext
    std::string decryptedText = rsaDecrypt(ciphertext, privateKey);
    std::cout << "Decrypted Text: " << decryptedText << std::endl;

    return 0;
}
