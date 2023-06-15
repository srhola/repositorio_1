// Type your code here, or load an example.
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <locale.h>
int main(void){
    setlocale(LC_CTYPE,"Spanish" );
    char s[]= "abcdefghijklmnñopqrstuvwxyz";
    char d[27];
    memcpy(d,s, sizeof(char)*27);
    printf("d: %s \n",d);
    char e[10];
    memcpy(e,s+8, sizeof(char)*9);
    e[9]='\0';
    printf("e: %s \n",e);
    char c = 'K';
 
    int i = int(c);
    int n= 37;
    char k= char(n);
    printf("i: %u \n",i);
    std::cout << k << std::endl; 
}
