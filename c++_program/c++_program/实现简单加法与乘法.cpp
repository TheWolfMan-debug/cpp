#include <iostream>

int main()
{
    int data1 = 0, data2 = 0;
    std::cout << "Please input two data:" << std::endl;
    std::cin >> data1 >> data2;
    std::cout << "The two data's sum is:\n" << data1 + data2 << std::endl;
    std::cout << "The two data's multiply is:\n" << data1 * data2 << std::endl;
    return 0;
}
