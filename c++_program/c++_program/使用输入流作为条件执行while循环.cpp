#include <iostream>

int main()
{
    int sum = 0, value = 0;
    while (std::cin >> value)
    {
        sum += value;
    }
    std::cout << "Sum is: " << sum << std::endl;

    //如何结束用户输入
        //1.用户在控制台中输入文件结束符（ctrl+z），再按回车
        //2.用户输入一个错误数据，如数据类型不符，在按回车
    return 0;
}
