//funcion para CONVERTIR DE HEXADECIMAL A DECIMAL 
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <math.h>

//Ejemplo conversion dec a hex => 125/16=7 resto= 13 =>dec2hex(125)=7D


int conditions(int value)
{
    //convert to ASCII
    if (value>=0 && value<=9){
        value=value+48;
    }else if(value>=10 && value<=15){
        value=value+55;
    }  
    return value;
}


int dec2hex(int x){
    std::cout<<"----------------------------------"<<std::endl;
    std::cout<<"Funcion dec2hex:"<<std::endl;
    std::cout<<"Valor introducido:"<<x<<std::endl;
    int p=0;
    int a;
    int resto;
    std::vector<int> myvector;
    std::vector<int> miresto;
    while(x>0){
        a=x;
        x=x/16;
        resto=a-x*16;   
        std::cout<<"X:"<<x<<" Resto:"<<resto<<std::endl;
        myvector.push_back(x);
        miresto.push_back(resto);
        p=p+1;
    } 
    //std::cout<<"P:"<<p<<std::endl;
    int mult[p];
    int conversion[p];
    int acum=0;
    for (int i = p-1; i >= 0; i--)
    {        
        conversion[i]=miresto[i];
        //conversion[i]=conditions(miresto[i]);
        if (conversion[i]>=0 && conversion[i]<=9){
            conversion[i]=conversion[i]+48;
        }else if(conversion[i]>=10 && conversion[i]<=15){
            conversion[i]=conversion[i]+55;
        }
        mult[i]=miresto[i]*pow(16,i);
        acum=acum+mult[i];
        std::cout<<"Resto ["<<i<< "]: "<<miresto[i]<<" Multiplicacion: "<<mult[i]<<" Suma:"<<acum<<std::endl;
        std::cout<<"hexa:"<<(char)conversion[i]<<std::endl;    
    }
    //int sumatoria=miresto[2]*pow(16,2)+miresto[1]*pow(16,1)+miresto[0]*pow(16,0);
    std::cout<<"Comprobacion:"<<acum<<std::endl;
    
    return 0;
}

int main(void){
    int x=719;
    dec2hex(x);
    std::cout<<"----------------------------------"<<std::endl;
    int y=16;
    int k=conditions(y);
    std::cout<<"K:"<<k<<std::endl;
    char senbu=(char)k;
    std::cout<<"K ASCII:"<<senbu<<std::endl;
    return 0;
}


