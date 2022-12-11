#include <iostream>
#include <fstream>
#include <string>

// addx V - 2 cycles
// noop - 1 cycle

// 40 wide 6 high

int main()
{
    std::ifstream file("input.txt");
    std::string line;

    int x = 1;
    int cycle = 1;
    int crt = 0;
    while (std::getline(file, line))
    {
        int spos = x;
        int to_do = 2;
        if (line == "noop")
            to_do = 1;

        for (; to_do > 0; to_do--)
        {
            if (spos == crt || spos+1==crt || spos-1==crt)
                std::cout << "#";
            else
                std::cout << ".";
            if (crt == 39) {
                std::cout<<std::endl;
            }
            crt++;
            if (crt > 39)
                crt = 0;
            cycle++;
        }
        if (line != "noop")
            x += std::stoi(line.substr(5));
    }
}
