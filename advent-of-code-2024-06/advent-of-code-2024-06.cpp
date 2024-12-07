// advent-of-code-2024-06.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

int main()
{
    std::ifstream file("input.txt");
    if (!file.is_open()) {
        std::cout << "failed to open" << std::endl;
        return 1;
    }
    std::string line;
    std::getline(file, line);
    int lineSize = line.size() + 1;
    file.seekg(-lineSize - 1, std::ios::cur);
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    int i = content.find('^');
    int s = 0;
    int step = -lineSize;
    int direction = 0;
    int maxSize = content.size();
    std::unordered_map<int, int> m;
    while (true) {
        if (m[i] != 1)
        {
            s++;
            m[i] = 1;
        }
        i += step;
        if (i < 0 || i >= maxSize || content[i] == '\n') break;
        if (content[i] == '#')
        {
            i -= step;
            direction++;
            switch (direction % 4)
            {
            case 1:
                step = 1;
                break;
            case 2:
                step = lineSize;
                break;
            case 3:
                step = -1;
                break;
            case 0:
                step = -lineSize;
                break;
            }
        }
    }
    std::cout << s << std::endl;
    std::cout << "Hello World!\n";
}