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

void AddSortedList(Node*& pH, int x) {
	if (pH == nullptr) return;
	Node* pIns = new Node;
	pIns->data = x, pIns->pNext = nullptr;
	if (pH->data >= x) {
		pIns->pNext = pH;
		pH = pIns;
		return;
	}
	Node* pCur = pH;
	while (pCur->pNext != nullptr) {
		if (pCur->pNext->data >= x) {
			pIns->pNext = pCur->pNext;
			pCur->pNext = pIns;
			break;
		}
		pCur = pCur->pNext;
	}
	return;
}

void ListofSum(Node* pH) {
	int sum = 0;
	Node* pCur = pH;
	while (pCur->pNext != nullptr) {
		sum = sum + pCur->data;
		pCur->data = sum;
		pCur = pCur->pNext;
	}
	return;
}

pair<Node*, Node*> Separate(Node* pH) {
	Node* pf = nullptr; 
	Node* ps = nullptr;
	if (pH == nullptr) return { pf, ps };
	if (pH->pNext == nullptr) {
		pf = pH;
		return { pf, ps };
	}
	pf = pH, ps = pH->pNext;
	Node* pfcur = pf;
	Node* pscur = ps;
	int type = 0;
	Node* pCur = pH->pNext->pNext;
	while (pCur != nullptr) {
		if (type == 0) {
			pfcur->pNext = pCur;
			pfcur = pCur;
		}
		else {
			pscur->pNext = pCur;
			pscur = pCur;
		}
		pCur = pCur->pNext;
		type = type ^ 1;
	}
	pfcur->pNext = nullptr;
	pscur->pNext = nullptr;
	return {pf, ps};
}

Node* Union(Node* a, Node* b) {
	Node* pH;
	if (a == nullptr) {
		pH = b;
		return pH;
	}
	if (b == nullptr) {
		pH = a;
		return pH;
	}
	Node* pa = a; pa = pa->pNext;
	Node* pb = b; pb = pb->pNext;
	pH = a; pH->pNext = b;
	Node* pCur = b;
	while (pa != nullptr & pb != nullptr){
		pCur->pNext = pa; pa = pa->pNext;
		pCur = pCur->pNext;
		pCur->pNext = pb; pb = pb->pNext;
		pCur = pCur->pNext;
	}
	if (pa != nullptr) {
		pCur->pNext = pa;
	}
	else {
		pCur->pNext = pb;
	}
	return pH;
}