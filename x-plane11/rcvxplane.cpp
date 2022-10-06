//añadir -lws2_32 al compilar de manera que g++.exe -o rcvxplane.exe rcvxplane.cpp -lws2_32
//X-plane11 ip:192.168.0.1 port:49000
#include <winsock.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <chrono>
#include <thread>
int main(int argc, char **argv)
{
	WSADATA wsda;
	// inicio de variables
	char szMessage[512];
   	int iMessageLen;
   	int ret;
   	char szAddress[64];
   	int iPort;
   	SOCKET s;					// Our UDP socket handle
   	SOCKADDR_IN addr,			// The local interface address
               remote_addr;		// The sender's address
   	int iRemoteAddrLen;			// Contains the length of remte_addr, passed to recvfrom
   	// Checkeo de argumentos, se imprime en consola que argumentos se deben ingresar, si al ejecutar este código, faltan argumentos 
   	if(argc != 2 ||
      (argc==2 && strcmp((char *) &argv[1][0], "/?")==0))    //argv[1][0] toma el segundo argumento argv[1]  y lo coloca antes que el primer argumento argv[0]
   	{
    	printf("wsudprcv port\n");
    	printf("   port:   the port the server should listen to\n");
    	exit(1);
   	}
   	printf("%s\n", &argv[1][0]);
   	iPort = atoi((char *) &argv[1][0]); //se convierte a integer
   	if(iPort<0 || iPort>65563)
    {
       printf("Invalid port number! (%s)\n", argv[2]);
       exit(1);
    }
    iMessageLen = 512;			// Set to the length of szMessage buffer
    // Load version 1.1 of Winsock
    WSAStartup(MAKEWORD(1,1), &wsda);
    // Create an UDP socket
    printf("Creating socket...");
    s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    // Error?
    if(s == SOCKET_ERROR)
    {
       printf("Error\nCall to socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP); failed with:\n%d\n", WSAGetLastError());
       exit(1);
    }
    printf("OK\n");
    // Fill in the interface information
    printf("Binding socket...");
    addr.sin_family = AF_INET;
    addr.sin_port = htons(iPort); //host to network short (LEAST SIGNIFICANT BYTE ORDER TO MOST SIGNIFICANT BYTE ORDER)
    addr.sin_addr.s_addr = INADDR_ANY; // acepta cualquier conexion sin necesidad de conocer la direccion ip 
    //chequeo de errores de binding 
    if(bind(s, (struct sockaddr *) &addr, sizeof(addr)) == SOCKET_ERROR)
    {
       printf("Error\nCall to bind(s, (struct sockaddr *) &addr, sizeof(addr)); failed with:\n%d\n", WSAGetLastError());
       exit(1);
    }
    printf("OK\n");
    // Ready to receive data
    printf("Waiting for packets (Press Ctrl-C to exit)...");
    iRemoteAddrLen = sizeof(remote_addr);

    int x;
    x=1;
    while (x<100)
    {
    	printf("%d\n", x);
    	x=x+1;
    	std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    	ret = recvfrom(s, szMessage, iMessageLen, 0, (struct sockaddr *) &remote_addr, &iRemoteAddrLen); //linea que recibe data 

	    //chequeo de errores al recivir datos 
	    if(ret == SOCKET_ERROR)
	    {
	       printf("Error\nCall to recvfrom(s, szMessage, iMessageLen, 0, (struct sockaddr *) &remote_addr, &iRemoteAddrLen); failed with:\n%d\n", WSAGetLastError());
	       exit(1);
	    }
	    printf("Packet received\n");
	    iMessageLen = ret;		// Length of the data received
	    szMessage[iMessageLen] = '\0';		// Convert to cstring
	    printf("\"%s\" received from %s\n", szMessage, inet_ntoa(remote_addr.sin_addr));
    } 

    closesocket(s);
    WSACleanup();

    return 0;


}




