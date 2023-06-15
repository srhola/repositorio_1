#include <iostream>
#include <bitset>

int main() {
    typedef std::bitset<16> _16bits;
    int a=0b101;
    int b=0b10110;
    b<<=4;
    int c=a|b;
    std::cout<< std::bitset<10>(c)<<std::endl;
    std::cout<< _16bits(68)<<std::endl;
    return 0;
}
