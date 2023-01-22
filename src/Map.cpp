#include "Map.h"
#include "General.h"

Map::Map(string filePath)
{
    this->filePath = filePath;
    this->paths = new Path();
    this->collisions = new Path();
}

Map::~Map()
{
    delete this->paths;
    delete this->collisions;
}

vector<string> Map::loadData()
{
    cout << "Loading data..." << endl;
    this->file = new ifstream(this->filePath);
    if (!file->is_open())
    {
        cout << "File " << this->filePath << " not found" << endl;
        getchar();
        exit(1);
    }

    vector<string> lines;
    for (int i = 0; i < 3; i++)
    {
        string line;
        getline(*file, line);
        lines.push_back(line);
    }

    file->close();
    return lines;
}

void Map::setCoordinates(string s)
{
    cout << "Setting coordinates..." << endl;
    auto strCoordinace = tokenize(s, "-");
    this->minDistance = std::stoi(strCoordinace.at(0));
    this->maxDistance = std::stoi(strCoordinace.at(1));
}

vector<Move> Map::makeMoves(string s)
{
    cout << "Making moves..." << endl;
    auto strDriver = tokenize(s, ",");
    vector<Move> moves;
    for (auto x : strDriver)
    {
        Move move(x);
        moves.push_back(move);
    }

    strDriver.clear();
    return moves;
}

vector<Point> Map::executeMoves(vector<Move> moves)
{
    cout << "Executing moves..." << endl;
    vector<Point> points;
    Point tmpPoint(0, 0);
    points.push_back(tmpPoint);

    for (auto &x : moves)
    {
        while (x.moreSteps() == true)
        {
            tmpPoint = tmpPoint.newPoint(x);
            points.push_back(tmpPoint);
        }
    }
    return points;
}

void Map::processData(vector<string> data)
{
    cout << "Start processing data..." << endl;
    if (data.size() < 3)
    {
        cout << "processData: Too little data." << endl;
        getchar();
        exit(1);
    }

    std::ofstream resultsFile;
    resultsFile.open(this->resultFileName());

    this->setCoordinates(data.at(0));
    auto moves1 = makeMoves(data.at(1));
    auto moves2 = makeMoves(data.at(2));

    auto points1 = executeMoves(moves1);
    auto points2 = executeMoves(moves2);
    moves1.clear();
    moves2.clear();

    this->paths->insertAll(points1, 1);
    this->paths->insertAll(points2, 2);
    points1.clear();
    points2.clear();

    this->collisions = this->paths->copyCollisions(this->minDistance, this->maxDistance);
    this->collisions->printAll(resultsFile);

    resultsFile.close();
    cout << "End processing data..." << endl;
}

PathPart Map::getResultCollision()
{
    return this->collisions->chooseFirst();
}

void Map::showResult()
{
    if (this->collisions->size() == 0)
    {
        cout << "There is no suitable result." << endl;
    }
    else
    {
        auto collision = this->getResultCollision();
        Point p(collision.first);
        cout << "The encounter of drivers occurred at:" << endl;
        cout << " -> [" << p.getX() << ":" << p.getY() << "]" << endl;

        for (auto &driver : collision.second)
            cout << " -> Driver number " << driver.getId() << " arrived after: " << driver.getSteps() << endl;
    }
}

string Map::resultFileName()
{
    auto copy = this->filePath;
    eraseSubStr(copy, ".txt");
    return copy + "-results.txt";
}
