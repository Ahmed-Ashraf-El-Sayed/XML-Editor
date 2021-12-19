#ifndef COMPRESS_H
#define COMPRESS_H



#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<time.h>
#include<stdlib.h>
using namespace std;
#define Char_size 256 //Ascii characterset only
struct Node;
void Mindownheap(vector<Node*> &A,int i,int length);
Node* Extract_min(vector<Node*> &A)  ;
void Insert_MinHeap(vector<Node*> &A,Node* element)   ;
void Build_Minheap(vector<Node*> &A,int length);
void store_codes(Node* Root,char single_code[],int index,vector<long long int> &Huffman_codemap) ;
void store_tree(ofstream &input,Node* Root) ;
Node* Huffman(long long int Count[]) ;
void Write_compressed(ifstream &input,ofstream &output,vector<long long int > &Huffman_codemap);
void compress(string  inputFile);
#endif