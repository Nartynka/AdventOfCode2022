#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream file("input.txt");
    std::string line;
    int max = 0;
    int max2 = 0;
    int max3 = 0;
    int calories = 0;
    while (std::getline(file, line))
    {
        if (line != "")
        {
            calories += std::stoi(line);
        }
        else
        {
            if (calories > max) {
                max3 = max2;
                max2 = max;
                max = calories;
            }
            else if (calories > max2) {
                max3 = max2;
                max2 = calories;
            }
            else if (calories > max3) {
                max3 = calories;
            }
            calories = 0;
        }
    }
            std::cout << max << std::endl;
            std::cout << max2 << std::endl;
            std::cout << max3 << std::endl;
            std::cout << max+max2+max3 << std::endl;
            std::cout << std::endl;
            std::cout << std::endl;
}
