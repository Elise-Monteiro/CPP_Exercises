#include <iostream>
#include <string>  

int main()
{
    int var = 0;
    std::cin >> var;
    std::string word;
    std::cin >> word;
    std::cout << var << std::endl;
    std::cout << word << std::endl;
    std::cout << "Hello world!" << word << std::endl;
    return 0;
}