
#ifndef UKOL_RESENI_POINTDATA_H
#define UKOL_RESENI_POINTDATA_H

#pragma once
#include <string>
#include <iostream>
#include <ostream>

class PointData
{
private:
    int id;
    int steps;

public:
    PointData(int, int);
    ~PointData() = default;

    std::string toString();
    void print(std::ostream &stream = std::cout);
    int getSteps();
    int getId();
};

#endif // UKOL_RESENI_POINTDATA_H
