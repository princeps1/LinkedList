#pragma once
#include "LListNode.h"
class LList
{
protected:
	LListNode* head;
public:
	LList();
	~LList();
	bool isEmpty();
	void addToHead(int el);
	void addToTail(int el);
	int deleteFromHead();
	int deleteFromTail();
	LListNode* findNodePtr(int el);
	LListNode* getHead();
	LListNode* getNext(LListNode* ptr);
	int getHeadEl();
	int getNextEl(int el);
	void printAll();
	bool isInList(int el);
	void deleteEl(int el);
	LListNode* removeNodeFromHead();

	//ISPITNI ROKOVI
	int swapPairs(int data1, int data2);//

	LList* extraEven();//
	LList* swap(LList* listPom);//

	void GroupElements();//

	void invertSublist(int data1, int data2);//

	LList* SplitOrMove();//

	void injectOrRemove(int br);//
};

