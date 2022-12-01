#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream file("input.txt");
    std::string line;
    int max = 0;
    int calories = 0;
    while (std::getline(file, line))
    {
        if (line != "")
        {
            calories += std::stoi(line);
        }
        else
        {
            if (calories > max)
            {
                max = calories;
            }
            calories = 0;
        }
    }
    std::cout << max;
}
