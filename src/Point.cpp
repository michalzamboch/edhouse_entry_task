#include "Point.h"
#include "General.h"

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

Point::Point(string s) {
    auto vec = tokenize(s, ":");
    this->x = std::stoi(vec.at(0));
    this->y = std::stoi(vec.at(1));;
}

string Point::toString() {
    return std::to_string(this->x) + ":" + std::to_string(this->y);
}

void Point::print(std::ostream &stream) {
    stream << this->toString() << "\n";
}

Point Point::newPoint(Move &move) {
    auto tmpX = this->x;
    auto tmpY = this->y;

    switch (move.getDirection())
    {
    case 'N': tmpY++;
        break;
    case 'S': tmpY--;
        break;
    case 'E': tmpX++;
        break;
    case 'W': tmpX--;
        break;
    }
    move.oneStep();

    return Point(tmpX, tmpY);
}

int Point::getX() {
    return this->x;
}

int Point::getY() {
    return this->y;
}
