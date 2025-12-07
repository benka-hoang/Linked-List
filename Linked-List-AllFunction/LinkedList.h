#pragma once
#include<fstream>

using namespace std;

struct Node {
	int data;
	Node* pNext;
};

void Clean(Node* pH);
void InputFile(ifstream& inp, Node*& pH);
void OutputFile(ofstream& out, Node* pH);

void Remove1stX(Node*& pH, int x);
void RemoveAllX(Node*& pH, int x);

void RemoveDuplicates(Node*& pH);

void Reverse(Node*& pH);

void InsertEvenNumbers(Node*& pH);
