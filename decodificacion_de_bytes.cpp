#include <iostream>
#include <cstring>

int main() {
    //unsigned char bytes[] = {21, 205, 91, 7}; // Bytes de ejemplo
    //unsigned char bytes[]={182,218,61,66,146,157,244,194};
    unsigned char bytes[]={184,218,61,66,146,157,244,194, 3, 17, 202, 67};
    // Crear un entero para almacenar el resultado
    int numero;
    
    struct XPlaneData{
        char prologue[5];
        unsigned char index[sizeof(int)];
        unsigned char latitude[sizeof(float)];
        unsigned char longitude[sizeof(float)];
        unsigned char altitude[sizeof(float)];
        unsigned char altitude_ground[sizeof(float)];
        unsigned char on_runway[sizeof(float)];
        unsigned char altitude_ind[sizeof(float)];
        unsigned char latitude_origin[sizeof(float)];
        unsigned char longitude_origin[sizeof(float)];
    };
    XPlaneData xp;
    std::cout<<sizeof(xp)<<std::endl;
    struct cone {
        float co;
        float ne;
        float jo;

    };
    cone conejo;
    // Copiar los bytes al entero utilizando un puntero
    std::memcpy(&numero, bytes, sizeof(int));
    
    std::memcpy(&conejo, bytes, sizeof(cone));
    float u=static_cast<float>(conejo.co);
    float sa=static_cast<float>(conejo.ne);
    float gi=static_cast<float>(conejo.jo);

    std::cout << "Lat: " << u << std::endl;
    std::cout << "Lon: " << sa << std::endl;
    std::cout << "Alt: " << gi << std::endl;
    // Mostrar el entero resultante
    std::cout << "Entero: " << numero << std::endl;
    
    // Crear un integer para almacenar el resultado
    float number;

    // Copiar los bytes al float utilizando un puntero
    std::memcpy(&number, bytes, sizeof(float));
     std::cout << "float: " << number << std::endl;

    return 0;
}
