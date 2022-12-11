#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

struct Monkey
{
    std::vector<int> items;
    std::string operation_sign;
    int operation_number;
    int divided_by;
    int true_monkey;
    int false_monkey;
    int times = 0;
};

int main()
{
    std::ifstream file("input.txt");
    std::string line;
    std::vector<Monkey> monkeys;

    // PARSING INPUT
    while (std::getline(file, line))
    {
        if (line.find("Monkey") != std::string::npos)
        {
            // new monkey
            Monkey m;
            //while in new monkey
            while (line != "" && std::getline(file, line))
            {
                if (line.find("Starting")!=std::string::npos)
                {
                    std::string items = line.substr(line.find(":")+2);
                    while (items.length()>1)
                    {
                        std::string item = items.substr(0, items.find(","));
                        m.items.push_back(std::stoi(item));
                        items = items.substr(items.find(",")+2);
                    }
                }
                if (line.find("Operation") != std::string::npos)
                {
                    m.operation_sign = line.substr(line.find("old") + 4, 1);
                    std::string operation = line.substr(line.find("old") + 6);
                    if (operation == "old")
                        m.operation_number = -1;
                    else
                        m.operation_number = std::stoi(line.substr(line.find("old") + 6));
                }
                if (line.find("Test") != std::string::npos)
                    m.divided_by = std::stoi(line.substr(line.find("by") + 3));
                if (line.find("true") != std::string::npos)
                    m.true_monkey = stoi(line.substr(line.find("monkey") + 7));
                if (line.find("false") != std::string::npos)
                    m.false_monkey = stoi(line.substr(line.find("monkey") + 7));
            }
            monkeys.push_back(m);
        }
    }
    // 1. moneky inspect first item
    // 2. operation is done
    // 3. item / 3 and rounded down
    // 4. test
    // 5. item goes to monkey from the test
    // 6. monkey inspect next item
    for (int i = 0; i < 20; i++)
    {
        for (Monkey &m : monkeys)
        {
            std::vector<int> items2 = m.items;
            for (int item : m.items)
            {
                m.times++;
                // 2. operation
                if (m.operation_number == -1)
                {
                    if (m.operation_sign == "+")
                        item = item + item;
                    else if(m.operation_sign == "*")
                        item = item * item;
                }
                else
                {
                    if (m.operation_sign == "+")
                        item = item + m.operation_number;
                    else if (m.operation_sign == "*")
                        item = item * m.operation_number;
                }
                // 3. divide by 3
                item = std::floor(item / 3);
                // 4. test 5. item goes to monkey
                if (item % m.divided_by == 0)
                {
                    monkeys[m.true_monkey].items.push_back(item);
                    items2.erase(items2.begin());
                }
                else
                {
                    monkeys[m.false_monkey].items.push_back(item);
                    items2.erase(items2.begin());
                }
            }
            m.items = items2;
        }
    }
    for (Monkey m : monkeys)
    {
        std::cout << "Times: " << m.times << std::endl;
    }
}