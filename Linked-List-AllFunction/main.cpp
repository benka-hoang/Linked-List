#include<iostream>
#include<fstream>
#include"LinkedList.h"
//#define _CRTDBG_MAP_ALLOC
//#include <crtdbg.h>
//#include <stdlib.h>

using namespace std;

int main() {
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	ifstream inp("input.txt"); ofstream out("output.txt");
	Node* pH = nullptr;
	InputFile(inp, pH);
	ListofSum(pH);
	OutputFile(out, pH);
	Clean(pH);
	inp.close(); out.close();
	return 0;
}