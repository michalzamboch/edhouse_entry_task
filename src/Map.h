#ifndef UKOL_RESENI_MAP_H
#define UKOL_RESENI_MAP_H

#pragma once
#include <unordered_map>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <fstream>

#include "Move.h"
#include "PointData.h"
#include "Point.h"
#include "Path.h"

using std::unordered_map;
using std::vector;
using std::string;
using std::ifstream;
using std::cout;
using std::endl;

class Map {
private:
    string filePath;
    ifstream *file;

    int minDistance = 0;
    int maxDistance = 0;

    Path *paths;
    Path *collisions;

    void setCoordinates(string s);
    vector<Move> makeMoves(string s);
    vector<Point> executeMoves(vector<Move> moves);
    string resultFileName();

public:
    Map(string filePath);
    ~Map();

    vector<string> loadData();
    void processData(vector<string> data);

    PathPart getResultCollision();
    void showResult();
};

#endif //UKOL_RESENI_MAP_H
