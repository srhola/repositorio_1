//añadir -lws2_32 al compilar de manera que g++.exe -o gpt_xplanercv3.exe gpt_xplanercv3.cpp -lws2_32
//X-plane11 ip:192.168.0.1 port:49000
#include <iostream>
#include <cstring>
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

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

struct XPlaneData2{
    char prologue[5];
    unsigned char index[sizeof(int)];
    unsigned char dat1[sizeof(float)];
    unsigned char dat2[sizeof(float)];
    unsigned char dat3[sizeof(float)];
    unsigned char dat4[sizeof(float)];
    unsigned char dat5[sizeof(float)];
    unsigned char dat6[sizeof(float)];
    unsigned char dat7[sizeof(float)];
    unsigned char dat8[sizeof(float)];
};

struct XPlaneData_2variables{
    char prologue[5];
    unsigned char index_1[sizeof(int)];
    unsigned char dat1_1[sizeof(float)];
    unsigned char dat2_1[sizeof(float)];
    unsigned char dat3_1[sizeof(float)];
    unsigned char dat4_1[sizeof(float)];
    unsigned char dat5_1[sizeof(float)];
    unsigned char dat6_1[sizeof(float)];
    unsigned char dat7_1[sizeof(float)];
    unsigned char dat8_1[sizeof(float)];
    unsigned char index_2[sizeof(int)];
    unsigned char dat1_2[sizeof(float)];
    unsigned char dat2_2[sizeof(float)];
    unsigned char dat3_2[sizeof(float)];
    unsigned char dat4_2[sizeof(float)];
    unsigned char dat5_2[sizeof(float)];
    unsigned char dat6_2[sizeof(float)];
    unsigned char dat7_2[sizeof(float)];
    unsigned char dat8_2[sizeof(float)];
};

int funcion_20(XPlaneData2 xplaneData)
{
        unsigned char byte_lon[sizeof(float)];
        unsigned char byte_lat[sizeof(float)];
        unsigned char byte_alt[sizeof(float)];
        
        for (int i = 0; i < sizeof(xplaneData.dat1); i++) {
            byte_lon[i]=static_cast<int>(xplaneData.dat1[i]);
            byte_lat[i]=static_cast<int>(xplaneData.dat2[i]);
            byte_alt[i]=static_cast<int>(xplaneData.dat3[i]);
            //std::cout << "Byte lon " << i << ": " << byte_lon[i];
            //std::cout <<" Byte lat " << i << ": " << byte_lat[i];
            //std::cout <<" Byte alt " << i << ": " << byte_alt[i]  << std::endl;
        }
        // conversion de los bytes a float
        float longitud;
        float latitud;
        float altitud;
        std::memcpy(&longitud, byte_lon, sizeof(float));
        std::memcpy(&latitud, byte_lat, sizeof(float));
        std::memcpy(&altitud, byte_alt, sizeof(float));
        float u=static_cast<float>(latitud);
        float sa=static_cast<float>(longitud);
        float gi=static_cast<float>(altitud);
        std::cout << "Lat [deg]: " << u ;
        std::cout << " Lon [deg]: " << sa ;
        std::cout << " Alt [ftmsl]: " << gi << std::endl;
        //std::cout<<"String:"<<xplaneData.data<<std::endl;
    return 0; 
}

int funcion_general(XPlaneData2 xplaneData)
{
        unsigned char byte_dat1[sizeof(float)];
        unsigned char byte_dat2[sizeof(float)];
        unsigned char byte_dat3[sizeof(float)];
        unsigned char byte_dat4[sizeof(float)];
        unsigned char byte_dat5[sizeof(float)];
        unsigned char byte_dat6[sizeof(float)];
        unsigned char byte_dat7[sizeof(float)];
        unsigned char byte_dat8[sizeof(float)];

        
        for (int i = 0; i < sizeof(xplaneData.dat1); i++) {
            byte_dat1[i]=static_cast<int>(xplaneData.dat1[i]);
            byte_dat2[i]=static_cast<int>(xplaneData.dat2[i]);
            byte_dat3[i]=static_cast<int>(xplaneData.dat3[i]);
            byte_dat4[i]=static_cast<int>(xplaneData.dat4[i]);
            byte_dat5[i]=static_cast<int>(xplaneData.dat5[i]);
            byte_dat6[i]=static_cast<int>(xplaneData.dat6[i]);
            byte_dat7[i]=static_cast<int>(xplaneData.dat7[i]);
            byte_dat8[i]=static_cast<int>(xplaneData.dat8[i]);

        }
        // conversion de los bytes a float
        float dat1;
        float dat2;
        float dat3;
        float dat4;
        float dat5;
        float dat6;
        float dat7;
        float dat8;

        std::memcpy(&dat1, byte_dat1, sizeof(float));
        std::memcpy(&dat2, byte_dat2, sizeof(float));
        std::memcpy(&dat3, byte_dat3, sizeof(float));
        std::memcpy(&dat4, byte_dat4, sizeof(float));
        std::memcpy(&dat5, byte_dat5, sizeof(float));
        std::memcpy(&dat6, byte_dat6, sizeof(float));
        std::memcpy(&dat7, byte_dat7, sizeof(float));
        std::memcpy(&dat8, byte_dat8, sizeof(float));
        
        float d1=static_cast<float>(dat1);
        float d2=static_cast<float>(dat2);
        float d3=static_cast<float>(dat3);
        float d4=static_cast<float>(dat1);
        float d5=static_cast<float>(dat2);
        float d6=static_cast<float>(dat3);
        float d7=static_cast<float>(dat1);
        float d8=static_cast<float>(dat2);
        
        std::cout << "D1 : " << d1 ;
        std::cout << " D2: " << d2 ;
        std::cout << " D3: " << d3 << std::endl;
        //std::cout<<"String:"<<xplaneData.data<<std::endl;
    return 0; 
}

int funcion_general_2variables(XPlaneData_2variables xplaneData)
{
        unsigned char byte_dat1_1[sizeof(float)];
        unsigned char byte_dat2_1[sizeof(float)];
        unsigned char byte_dat3_1[sizeof(float)];
        unsigned char byte_dat4_1[sizeof(float)];
        unsigned char byte_dat5_1[sizeof(float)];
        unsigned char byte_dat6_1[sizeof(float)];
        unsigned char byte_dat7_1[sizeof(float)];
        unsigned char byte_dat8_1[sizeof(float)];

        unsigned char byte_dat1_2[sizeof(float)];
        unsigned char byte_dat2_2[sizeof(float)];
        unsigned char byte_dat3_2[sizeof(float)];
        unsigned char byte_dat4_2[sizeof(float)];
        unsigned char byte_dat5_2[sizeof(float)];
        unsigned char byte_dat6_2[sizeof(float)];
        unsigned char byte_dat7_2[sizeof(float)];
        unsigned char byte_dat8_2[sizeof(float)];
        
        for (int i = 0; i < sizeof(xplaneData.dat1_1); i++) {
            byte_dat1_1[i]=static_cast<int>(xplaneData.dat1_1[i]);
            byte_dat2_1[i]=static_cast<int>(xplaneData.dat2_1[i]);
            byte_dat3_1[i]=static_cast<int>(xplaneData.dat3_1[i]);
            byte_dat4_1[i]=static_cast<int>(xplaneData.dat4_1[i]);
            byte_dat5_1[i]=static_cast<int>(xplaneData.dat5_1[i]);
            byte_dat6_1[i]=static_cast<int>(xplaneData.dat6_1[i]);
            byte_dat7_1[i]=static_cast<int>(xplaneData.dat7_1[i]);
            byte_dat8_1[i]=static_cast<int>(xplaneData.dat8_1[i]);

            byte_dat1_2[i]=static_cast<int>(xplaneData.dat1_2[i]);
            byte_dat2_2[i]=static_cast<int>(xplaneData.dat2_2[i]);
            byte_dat3_2[i]=static_cast<int>(xplaneData.dat3_2[i]);
            byte_dat4_2[i]=static_cast<int>(xplaneData.dat4_2[i]);
            byte_dat5_2[i]=static_cast<int>(xplaneData.dat5_2[i]);
            byte_dat6_2[i]=static_cast<int>(xplaneData.dat6_2[i]);
            byte_dat7_2[i]=static_cast<int>(xplaneData.dat7_2[i]);
            byte_dat8_2[i]=static_cast<int>(xplaneData.dat8_2[i]);            

        }
        // conversion de los bytes a float
        float dat1_1;
        float dat2_1;
        float dat3_1;
        float dat4_1;
        float dat5_1;
        float dat6_1;
        float dat7_1;
        float dat8_1;

        float dat1_2;
        float dat2_2;
        float dat3_2;
        float dat4_2;
        float dat5_2;
        float dat6_2;
        float dat7_2;
        float dat8_2;

        std::memcpy(&dat1_1, byte_dat1_1, sizeof(float));
        std::memcpy(&dat2_1, byte_dat2_1, sizeof(float));
        std::memcpy(&dat3_1, byte_dat3_1, sizeof(float));
        std::memcpy(&dat4_1, byte_dat4_1, sizeof(float));
        std::memcpy(&dat5_1, byte_dat5_1, sizeof(float));
        std::memcpy(&dat6_1, byte_dat6_1, sizeof(float));
        std::memcpy(&dat7_1, byte_dat7_1, sizeof(float));
        std::memcpy(&dat8_1, byte_dat8_1, sizeof(float));
        
        std::memcpy(&dat1_2, byte_dat1_2, sizeof(float));
        std::memcpy(&dat2_2, byte_dat2_2, sizeof(float));
        std::memcpy(&dat3_2, byte_dat3_2, sizeof(float));
        std::memcpy(&dat4_2, byte_dat4_2, sizeof(float));
        std::memcpy(&dat5_2, byte_dat5_2, sizeof(float));
        std::memcpy(&dat6_2, byte_dat6_2, sizeof(float));
        std::memcpy(&dat7_2, byte_dat7_2, sizeof(float));
        std::memcpy(&dat8_2, byte_dat8_2, sizeof(float));

        float d1_1=static_cast<float>(dat1_1);
        float d2_1=static_cast<float>(dat2_1);
        float d3_1=static_cast<float>(dat3_1);
        float d4_1=static_cast<float>(dat4_1);
        float d5_1=static_cast<float>(dat5_1);
        float d6_1=static_cast<float>(dat6_1);
        float d7_1=static_cast<float>(dat7_1);
        float d8_1=static_cast<float>(dat8_1);

        float d1_2=static_cast<float>(dat1_2);
        float d2_2=static_cast<float>(dat2_2);
        float d3_2=static_cast<float>(dat3_2);
        float d4_2=static_cast<float>(dat4_2);
        float d5_2=static_cast<float>(dat5_2);
        float d6_2=static_cast<float>(dat6_2);
        float d7_2=static_cast<float>(dat7_2);
        float d8_2=static_cast<float>(dat8_2);
        
        std::cout << "D1_1 : " << d1_1 ;
        std::cout << " D2_1: " << d2_1 ;
        std::cout << " D3_1: " << d3_1 << std::endl;
        std::cout << "D1_2 : " << d1_2 ;
        std::cout << " D2_2: " << d2_2 ;
        std::cout << " D3_2: " << d3_2 << std::endl;
        //std::cout<<"String:"<<xplaneData.data<<std::endl;
    return 0; 
}

int main() {
    // Inicializar Winsock
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "Error al inicializar Winsock" << std::endl;
        return 1;
    }

    // Configurar la dirección IP y el puerto para recibir datos
    const char* ip = "0.0.0.0";  // Dirección IP local (puedes cambiarlo si es necesario)
    int puerto = 49200;  // Puerto de datos de X-Plane (puedes cambiarlo si es necesario)

    // Crear un socket UDP
    SOCKET sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == INVALID_SOCKET) {
        std::cerr << "Error al crear el socket" << std::endl;
        WSACleanup();
        return 1;
    }

    // Configurar la dirección local
    sockaddr_in localAddr{};
    localAddr.sin_family = AF_INET;
    localAddr.sin_port = htons(puerto);
    if (inet_pton(AF_INET, ip, &(localAddr.sin_addr)) <= 0) {
        std::cerr << "Dirección IP inválida" << std::endl;
        closesocket(sockfd);
        WSACleanup();
        return 1;
    }

    // Enlazar el socket a la dirección local
    if (bind(sockfd, (const sockaddr*)&localAddr, sizeof(localAddr)) == SOCKET_ERROR) {
        std::cerr << "Error al enlazar el socket" << std::endl;
        closesocket(sockfd);
        WSACleanup();
        return 1;
    }

    // Buffer para almacenar los datos recibidos
    char buffer[1024];

    // Bucle para recibir los datos
    while (true) {
        sockaddr_in remoteAddr{};
        int addrLen = sizeof(remoteAddr);

        // Recibir los datos
        int bytesRecibidos = recvfrom(sockfd, buffer, sizeof(buffer) - 1, 0, (sockaddr*)&remoteAddr, &addrLen);
        if (bytesRecibidos == SOCKET_ERROR) {
            std::cerr << "Error al recibir los datos" << std::endl;
            break;
        }

        // Agregar el carácter nulo al final de los datos recibidos
        buffer[bytesRecibidos] = '\0';
        std::cout<<"bytes recibidos"<<bytesRecibidos<<std::endl;



        if (bytesRecibidos == sizeof(XPlaneData))
        {
            XPlaneData2 xplaneData;
            std::memcpy(&xplaneData, buffer, sizeof(XPlaneData));
            for (int i = 0; i < sizeof(xplaneData.index); i++) {
                std::cout << "Byte " << i << ": " << static_cast<int>(xplaneData.index[i]) << std::endl;
            }

            if (xplaneData.index[0]==20)
            {
                funcion_20(xplaneData);
            } else{
                funcion_general(xplaneData);
            }
        } else if(bytesRecibidos == sizeof(XPlaneData_2variables))
        {
            XPlaneData_2variables xplaneData;
            std::memcpy(&xplaneData, buffer, sizeof(XPlaneData_2variables));
            for (int i = 0; i < sizeof(xplaneData.index_1); ++i)
            {
                std::cout << "Byte " << i << ": " << static_cast<int>(xplaneData.index_1[i]) << std::endl;
            }
            for (int i = 0; i < sizeof(xplaneData.index_2); ++i)
            {
                std::cout << "Byte " << i << ": " << static_cast<int>(xplaneData.index_2[i]) << std::endl;
            }

            funcion_general_2variables(xplaneData);
        } else{
            std::cerr << "Tamaño de datos incorrecto" << std::endl;
            std::cout<<"bytesRecibidos:"<<bytesRecibidos<<std::endl;
            std::cout<<"sizeof(XPlaneData):"<<sizeof(XPlaneData)<<std::endl;
            continue;
        }


        // Comprobar que los datos recibidos tienen el tamaño correcto
        /*
        if (bytesRecibidos != sizeof(XPlaneData)) {
            std::cerr << "Tamaño de datos incorrecto" << std::endl;
            std::cout<<"bytesRecibidos:"<<bytesRecibidos<<std::endl;
            std::cout<<"sizeof(XPlaneData):"<<sizeof(XPlaneData)<<std::endl;
            continue;
        }

        // Convertir los datos recibidos a una estructura XPlaneData
        //XPlaneData2 xplaneData;
        //std::memcpy(&xplaneData, buffer, sizeof(XPlaneData));

        // Acceder a los campos de la estructura XPlaneData

        // Imprimir los datos recibidos
        //std::cout << "index: " << xplaneData.index << std::endl;
        //std::cout << "place: " << xplaneData.place << std::endl;
        //std::cout << "prologue: " << xplaneData.prologue << std::endl;

        // Conversion de los datos a formato de bytes 
        for (int i = 0; i < sizeof(xplaneData.index); i++) {
            std::cout << "Byte " << i << ": " << static_cast<int>(xplaneData.index[i]) << std::endl;
        }

        if (xplaneData.index[0]==20)
        {
            funcion_20(xplaneData);
        } else{
            funcion_general(xplaneData);
        }
        */

        
        //std::cout<<"String:"<<xplaneData.data<<std::endl;
    }
    // Cerrar el socket y limpiar Winsock
    closesocket(sockfd);
    WSACleanup();
    return 0;
}
