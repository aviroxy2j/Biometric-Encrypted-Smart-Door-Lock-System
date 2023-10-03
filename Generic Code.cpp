#include <iostream>
#include <vector>
#include <fstream>
#include <openssl/aes.h>
#include <openssl/rand.h>

// Function to read a file into a vector of bytes
std::vector<uint8_t> ReadFile(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        throw std::runtime_error("Failed to open file for reading");
    }

    // Determine the file size
    file.seekg(0, std::ios::end);
    std::streampos fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    // Read the file into a vector
    std::vector<uint8_t> fileData(fileSize);
    file.read(reinterpret_cast<char*>(fileData.data()), fileSize);
    return fileData;
}

// Function to write binary data to a file
void WriteFile(const std::string& filename, const std::vector<uint8_t>& data) {
    std::ofstream file(filename, std::ios::binary);
    if (!file) {
        throw std::runtime_error("Failed to open file for writing");
    }
    file.write(reinterpret_cast<const char*>(data.data()), data.size());
}

int main() {
    // Replace with your TIF image file path
    std::string imageFilePath = "fingerprint.tif";

    // Read the TIF image file and convert it to binary data
    std::vector<uint8_t> binaryData = ReadFile(imageFilePath);

    // Initialize the AES encryption key and IV (Initialization Vector)
    AES_KEY aesKey;
    uint8_t aesKeyData[16]; // AES-128 key size
    uint8_t ivData[16];    // IV size

    // Generate a random key and IV (for encryption and decryption)
    RAND_bytes(aesKeyData, sizeof(aesKeyData));
    RAND_bytes(ivData, sizeof(ivData));

    // Set up the encryption context
    AES_set_encrypt_key(aesKeyData, 128, &aesKey);

    // Encrypt the binary data
    std::vector<uint8_t> encryptedData(binaryData.size());
    AES_cbc_encrypt(binaryData.data(), encryptedData.data(), binaryData.size(), &aesKey, ivData, AES_ENCRYPT);

    // Save the encrypted data to a file
    std::string encryptedFilePath = "encrypted_fingerprint.bin";
    WriteFile(encryptedFilePath, encryptedData);

    std::cout << "Encryption complete. Encrypted data saved to " << encryptedFilePath << std::endl;
    std::cout << "Encryption key (hex): ";
    for (int i = 0; i < sizeof(aesKeyData); ++i) {
        std::cout << std::hex << static_cast<int>(aesKeyData[i]);
    }
    std::cout << std::endl;

    return 0;
}
