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
    printf("%#x\n",x);
    printf("%#x\n", c);
    
    un cos;
    cos.x = 1;

    printf("%#x\n", cos.y);

    return 0;
}