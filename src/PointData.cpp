#include "PointData.h"

PointData::PointData(int _id, int _steps)
{
    this->id = _id;
    this->steps = _steps;
}

std::string PointData::toString()
{
    return "(" + std::to_string(this->id) + ". " + std::to_string(this->steps) + ")";
}

void PointData::print(std::ostream &stream)
{
    stream << this->toString() << "\n";
}

int PointData::getSteps()
{
    return this->steps;
}

int PointData::getId()
{
    return this->id;
}
