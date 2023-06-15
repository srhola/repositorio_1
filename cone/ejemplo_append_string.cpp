#include <string>
#include <iostream>
#include <stdio.h>

using namespace std;

string añadir(int i, int j_max, string s){
    //Funcionamiento de esta funcion:
    // Esta funcion devuelve una string que es el resultado de una string inicial que concatena un integer en cada iteracion 

    for (int j=0; j<j_max; ++j  ){        
        s=s+to_string(i);
        i=i+1;
    }

    return s;
} 

int main(){
    int i=10;
    string s="A";
    
    string k=añadir(i,3,s);
    cout<<k<<endl; 
    return 0;
}
