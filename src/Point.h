#ifndef UKOL_RESENI_POINT_H
#define UKOL_RESENI_POINT_H

#pragma once
#include <string>
#include <iostream>

#include "Move.h"

using std::cout;
using std::endl;
using std::string;

class Point
{
private:
    int x;
    int y;

public:
    Point(int x, int y);
    Point(string s);
    ~Point() = default;
    Point newPoint(Move &move);

    string toString();
    void print(std::ostream &stream = std::cout);
    int getX();
    int getY();
};

#endif // UKOL_RESENI_POINT_H
