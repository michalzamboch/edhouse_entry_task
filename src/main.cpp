#include <iostream>
#include <unordered_map>
#include <string>

#include "Map.h"

void run(std::string filePath)
{
    auto map = new Map(filePath);
    auto data = map->loadData();
    map->processData(data);
    data.clear();

    std::cout << "---------------------" << std::endl;
    map->showResult();

    delete map;
}

int main()
{
    run("trace.txt");
    return 0;
}
