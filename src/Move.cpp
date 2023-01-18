#include "Move.h"
#include "General.h"

Move::Move(std::string s) {
    this->direction = s.at(s.length() - 1);
    removeChar(s, this->direction);
    this->count = std::stoi(s);
}

void Move::oneStep()
{
    if (this->moreSteps())
    {
        this->count--;
    }
}

bool Move::moreSteps() {
    return this->count > 0;
}

char Move::getDirection() {
    return this->direction;
}

std::string Move::toString() {
    return std::to_string(this->count) + this->direction;
}

void Move::print(std::ostream &stream) {
    stream << this->toString() << "\n";
}

int Move::getSteps() {
    return this->count;
}


