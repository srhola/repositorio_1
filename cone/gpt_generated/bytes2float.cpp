#include <iostream>
#include <cstring>

int main() {
    //unsigned char bytes[] = {0x42, 0xF6, 0x48, 0x40}; // Bytes de ejemplo
    unsigned char bytes[] = {7, 91 ,205, 21}; // Bytes de ejemplo
    // Crear un float para almacenar el resultado
    float number;

    // Copiar los bytes al float utilizando un puntero
    std::memcpy(&number, bytes, sizeof(float));

    // Mostrar el número de punto flotante resultante
    std::cout << "Número de punto flotante: " << number << std::endl;

    return 0;
}
