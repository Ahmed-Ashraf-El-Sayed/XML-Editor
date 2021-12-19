#ifndef DECOMPRESS_H
#define DECOMPRESS_H

#include<iostream>
#include<fstream>
#include<vector>
#include<time.h>
#include<stdlib.h>
#include<string>
using namespace std;
struct Node ;
Node* Make_Huffman_tree(ifstream &input);
void decode(ifstream &input,string filename,Node* Root,long long int Total_Freq) ;
void decompress(string inputFile);

#endif
