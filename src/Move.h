#ifndef UKOL_RESENI_MOVE_H
#define UKOL_RESENI_MOVE_H

#pragma once
#include <string>
#include <iostream>
#include <ostream>

class Move
{
private:
    int count;
    char direction;

public:
    Move(std::string);
    ~Move() = default;

    void oneStep();
    bool moreSteps();
    int getSteps();

    char getDirection();
    std::string toString();
    void print(std::ostream &stream = std::cout);
};

#endif // UKOL_RESENI_MOVE_H
