#include <iostream>

int main()
{
    int a, b;
    std::cout << "Please input two numbers." << std::endl;
    std::cin >> a >> b;

    for(int i=a; i<=b; i++) {
        std::cout << i << " ";
    }

    return 0;
}