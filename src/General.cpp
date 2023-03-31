#include "General.h"

vector<string> tokenize(string s, string del = " ")
{
    size_t end = s.find(del);
    size_t start = 0;

    vector<string> columns;

    while (end != -1)
    {
        columns.push_back(s.substr(start, end - start));
        start = end + del.size();
        end = s.find(del, start);
    }
    columns.push_back(s.substr(start, end - start));

    return columns;
}

void removeChar(string &my_str, char value)
{
    my_str.erase(remove(my_str.begin(), my_str.end(), value), my_str.end());
}

void removeChars(string &my_str, vector<char> values)
{
    for (auto x : values)
    {
        removeChar(my_str, x);
    }
}

void printList(vector<string> str)
{
    for (auto x : str)
    {
        cout << "-> " << x << endl;
    }
}

void printVector(vector<string> str)
{
    cout << "[ ";
    for (auto x : str)
    {
        cout << x << " ";
    }
    cout << "]" << endl;
}

void printVector(vector<vector<string>> strVecs)
{
    for (auto x : strVecs)
    {
        printVector(x);
    }
}

void eraseSubStr(std::string &mainStr, const std::string &toErase)
{
    size_t pos = mainStr.find(toErase);
    if (pos != std::string::npos)
    {
        mainStr.erase(pos, toErase.length());
    }
}
