#include <iostream>
#include <fstream>
#include <string>

// addx V - 2 cycles
// noop - 1 cycle

int main()
{
    std::ifstream file("input.txt");
    std::string line;

    int x = 1;
    int cycle = 1;
    int sum = 0;
    while (std::getline(file, line))
    {
        int to_do = 2;
        if (line == "noop")
            to_do = 1;
        for (; to_do > 0; to_do--)
        {
            if (cycle == 20 || cycle == 60 || cycle == 100 || cycle == 140 || cycle == 180 || cycle == 220)
                sum += cycle * x;
            cycle++;
        }
        if (line != "noop")
            x += std::stoi(line.substr(5));
    }
    std::cout << "Sum: " << sum;
}
