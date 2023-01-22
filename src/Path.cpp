#include "Path.h"

Path::~Path()
{
    for (auto &x : this->path)
    {
        x.second.clear();
    }
    this->path.clear();
}

void Path::insert(Point point, PointData data)
{
    if (contains(point) == false)
    {
        vector<PointData> vecData{data};
        this->path.insert({point.toString(), vecData});
    }
    else
    {
        this->path.at(point.toString()).push_back(data);
    }
}

void Path::insert(string key, vector<PointData> data)
{
    if (contains(key) == false)
    {
        this->path.insert({key, data});
    }
    else
    {
        for (auto x : data)
        {
            this->path.at(key).push_back(x);
        }
    }
}

void Path::insert(Point point, int id, int distance)
{
    this->insert(point, {id, distance});
}

bool Path::contains(string key)
{
    auto founded = this->path.find(key);
    return (founded != this->path.end());
}

bool Path::contains(Point point)
{
    return this->contains(point.toString());
}

void Path::remove(string key)
{
    this->path.erase(key);
}

void Path::remove(Point point)
{
    this->remove(point.toString());
}

void Path::printPathPart(PathPart part, std::ostream &stream)
{

    stream << part.first << " >";
    for (auto &x : part.second)
    {
        stream << " " << x.toString();
    }
    stream << "\n";
}

void Path::printAll(std::ostream &stream)
{
    for (auto &x : this->path)
    {
        printPathPart(x, stream);
    }
}

void Path::insertAll(vector<Point> points, int id, int distance)
{
    std::cout << "Inserting all..." << std::endl;

    for (auto &x : points)
    {
        PointData d(id, distance);
        this->insert(x, d);
        distance++;
    }
}

Path *Path::copyCollisions(int min, int max)
{
    std::cout << "Searching for collisions." << std::endl;
    Path *collisions = new Path();

    for (auto x : this->path)
    {
        if (x.second.size() >= 2)
        {
            if (this->validPointData(x.second, min, max))
            {
                collisions->insert(x.first, x.second);
            }
        }
    }

    return collisions;
}

bool Path::validDistance(vector<PointData> &data, int min, int max)
{
    for (auto &x : data)
    {
        if (!(x.getSteps() >= min && x.getSteps() <= max))
        {
            return false;
        }
    }

    return true;
}

bool Path::validIds(vector<PointData> &data)
{
    auto first = data.at(0).getId();
    for (int i = 1; i < data.size(); i++)
    {
        if (first != data.at(i).getId())
        {
            return true;
        }
    }
    return false;
}

bool Path::validPointData(vector<PointData> &data, int min, int max)
{
    return this->validDistance(data, min, max) && this->validIds(data);
}

unsigned long Path::size() const noexcept
{
    return (unsigned long)this->path.size();
}

PathPart Path::chooseFirst()
{
    if (this->size() > 0)
    {
        return *this->path.begin();
    }
    return PathPart();
}
