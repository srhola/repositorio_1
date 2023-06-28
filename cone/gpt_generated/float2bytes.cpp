#include <iostream>
#include <cstring>

int main() {
    float number = 3.14159f; // Floating-point number example

    // Create an array of bytes the size of a float
    unsigned char bytes[sizeof(float)];
    std::cout<<"size of float: "<< sizeof(float)<<std::endl;

    // Copy the contents of the float to the byte array
    std::memcpy(bytes, &number, sizeof(float));

    // Print the bytes individually
    for (int i = 0; i < sizeof(float); i++) {
        std::cout << "Byte " << i << ": " << static_cast<int>(bytes[i]) << std::endl;
    }

    return 0;
}
