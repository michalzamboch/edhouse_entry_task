
#ifndef UKOL_RESENI_PATH_H
#define UKOL_RESENI_PATH_H

#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>

#include "Point.h"
#include "PointData.h"

using std::string;
using std::vector;
using std::unordered_map;

using PathPart = std::pair<string, std::vector<PointData>>;

class Path
{
private:
    unordered_map<string, vector<PointData>> path;

public:
    Path() = default;
    ~Path();

    Path *copyCollisions(int min, int max);
    bool validDistance(vector<PointData>& data, int min, int max);
    bool validIds(vector<PointData>& data);
    bool validPointData(vector<PointData>& data, int min, int max);

    void insert(Point point, PointData data);
    void insert(Point point, int id, int distance);

    void insert(string key, vector<PointData> data);
    void insertAll(vector<Point> points, int id, int distance = 0);

    bool contains(string key);
    bool contains(Point point);
    void remove(string key);
    void remove(Point point);

    static void printPathPart(PathPart part, std::ostream &stream = std::cout);
    void printAll(std::ostream &stream = std::cout);
    unsigned long size() const noexcept;
    PathPart chooseFirst();
};


#endif //UKOL_RESENI_PATH_H
