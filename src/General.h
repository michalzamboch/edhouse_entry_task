#ifndef UKOL_RESENI_GENERAL_H
#define UKOL_RESENI_GENERAL_H

#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::vector;

vector<string> tokenize(string, string);

void printList(vector<string>);
void printVector(vector<string>);
void printVector(vector<vector<string>>);

void removeChar(string &, char);
void removeChars(string &, vector<char>);
void eraseSubStr(std::string &mainStr, const std::string &toErase);

#endif // UKOL_RESENI_GENERAL_H
