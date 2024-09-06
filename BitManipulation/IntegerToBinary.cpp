#include <iostream>

void printBit(int userNum, int binaryDivisor)
{
    std::cout << ((userNum / binaryDivisor) % 2);
}

void print8BitBinary (int userNum)
{
    printBit(userNum, 128);
    printBit(userNum, 64);
    printBit(userNum, 32);
    printBit(userNum, 16);
    
    std::cout << " ";
    
    printBit(userNum, 8);
    printBit(userNum, 4);
    printBit(userNum, 2);
    printBit(userNum, 1);
}

int main()
{
    std::cout << "Enter an integer between 0 and 255: ";
    int userNum{ };
    std::cin >> userNum;

    if (userNum > 255 || userNum < 0)
        std::cout << "Number out of bounds";
    else
        print8BitBinary(userNum);
    
    return 0;
}
