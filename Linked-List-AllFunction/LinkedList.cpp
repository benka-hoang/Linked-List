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
	pH = nullptr;
	Node* pCur = nullptr;
	int x; inp >> x;
	while (x != 0) {
		if (pH == nullptr) {
			pH = new Node;
			pH->data = x;
			pH->pNext = nullptr;
			pCur = pH;
		}
		else {
			pCur->pNext = new Node;
			pCur = pCur->pNext;
			pCur->data = x;
			pCur->pNext = nullptr;
		}
		inp >> x;
	}
	return;
}

void OutputFile(ofstream& out, Node* pCur) {
	while (pCur != nullptr) {
		out << pCur->data << " ";
		pCur = pCur->pNext;
	}
	out << 0 << "\n";
	return;
}

void Remove1stX(Node*& pH, int x) {
	if (pH == nullptr) return;
	if (pH->data == x) {
		Node* pDel = pH;
		pH = pH->pNext;
		delete pDel;
		return;
	}
	Node* pCur = pH;
	while (pCur->pNext != nullptr) {
		if (pCur->pNext->data == x) {
			Node* pDel = pCur->pNext;
			pCur->pNext = pCur->pNext->pNext;
			delete pDel;
			break;
		}
		pCur = pCur->pNext;
	}
	return;
}

void RemoveAllX(Node*& pH, int x) {
	Node* pPre = new Node;
	pPre->data = 0, pPre->pNext = pH;
	Node* pCur = pPre;
	while (pCur->pNext != nullptr) {
		if (pCur->pNext->data == x) {
			Node* pDel = pCur->pNext;
			pCur->pNext = pCur->pNext->pNext;
			delete pDel;
		}
		else {
			pCur = pCur->pNext;
		}
	}
	pH = pPre->pNext;
	delete pPre;
	return;
}

void RemoveDuplicates(Node*& pH) {
	Node* pCur = pH;
	while (pCur != nullptr) {
		if (pCur->data != 0) {
			int data = pCur->data;
			Node* pRun = pCur->pNext;
			while (pRun != nullptr) {
				if (pRun->data == data) {
					pRun->data = 0;
				}
				pRun = pRun->pNext;
			}
		}
		pCur = pCur->pNext;
	}
	RemoveAllX(pH, 0);
	return;
}

void Reverse(Node*& pH) {
	Node* pCur = pH;
	pH = nullptr;
	while (pCur != nullptr) {
		Node* pIns = pCur;
		pCur = pCur->pNext;
		pIns->pNext = pH;
		pH = pIns;
	}
	return;
}

void InsertEvenNumbers(Node*& pH) {
	if (pH == nullptr) return;
	int vIns = 2;
	Node* pCur = pH;
	Node* pIns = new Node;
	pIns->data = 2, pIns->pNext = pH;
	pH = pIns;
	while (pCur->pNext != nullptr) {
		vIns += 2;
		pIns = new Node;
		pIns->data = vIns, pIns->pNext = pCur->pNext;
		pCur->pNext = pIns;
		pCur = pCur->pNext->pNext;
	}
	return;
}