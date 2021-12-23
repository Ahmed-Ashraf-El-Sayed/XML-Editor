#ifndef CHECKCONSISTENCY_H
#define CHECKCONSISTENCY_H

#include<iostream>
#include<stack>
#include<string>
#include<fstream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
string removeSpaces(string str);         //used to remove spaces because it will be an error
bool XMLConsistency(string file_name);   //if the output is zero there is no error and if the output of one then there is error

#endif // CHECKCONSISTENCY_H
