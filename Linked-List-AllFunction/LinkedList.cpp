#include "LinkedList.h"
#include<fstream>
#include<iostream>

using namespace std;

void Clean(Node* pH) {
	Node* pDel = nullptr;
	while (pH != nullptr) {
		pDel = pH;
		pH = pH->pNext;
		delete pDel;
	}
	return;
}

void InputFile(ifstream& inp, Node*& pH) {
	pH = new Node;
	pH->data = 0;
	pH->pNext = nullptr;
	Node* pCur = pH;
	int x; inp >> x;
	while (x != 0) {
		pCur->data = x;
		pCur->pNext = new Node;
		pCur = pCur->pNext;
		pCur->data = 0;
		pCur->pNext = nullptr;
		inp >> x;
	}
	return;
}

void OutputFile(ofstream& out, Node* pCur) {
	while (pCur != nullptr) {
		out << pCur->data << " ";
		pCur = pCur->pNext;
	}
	return;
}

void RemoveAllX(Node*& pH, int x) {
	Node* pAnswer = new Node;
	pAnswer->data = 0;
	pAnswer->pNext = nullptr;
	Node* pUpd = pAnswer;
	Node* pCur = pH;
	// Create new Linked-List
	while (pCur != nullptr && pCur->data != 0) {
		if (pCur->data != x) {
			pUpd->data = pCur->data;
			pUpd->pNext = new Node;
			pUpd = pUpd->pNext;
			pUpd->data = 0, pUpd->pNext = nullptr;
		}
		pCur = pCur->pNext;
	}
	// Deallocate Linked-List
	Node* pDel = nullptr;
	pCur = pH;
	while (pCur != nullptr) {
		pDel = pCur;
		pCur = pCur->pNext;
		delete pDel;
	}
	pH = pAnswer;
	return;
}