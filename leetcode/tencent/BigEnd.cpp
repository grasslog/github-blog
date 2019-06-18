#include <iostream>
#include <stdio.h>

union un
{
    int x;
    char y;
};

int main()
{
    short int x = 0x1234;
    char c = x;
    printf("#%x\n", c);
    if(c == 0x12){
        std::cout << "big end." << std::endl;
    }else {
        std::cout << "litter end." << std::endl;
    } 

    return 0;
}