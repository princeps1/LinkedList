#include "DList.h"



DList::DList()
{
	head = NULL;
}


DList::~DList()
{
	while (!isEmpty())
	{
		int tmp = deleteFromHead();
	}
}

DListNode* DList::findNodePtr(int el)
{
	if (isEmpty())
		throw new exception("List is empty");
	DListNode* ret = head;
	while (ret != NULL && ret->info != el)
	{
		ret = ret->next;
	}
	return ret;
}

int DList::getHeadEl()
{
	if (isEmpty())
		throw new exception("List is empty");
	return head->info;
}

int DList::getNextEl(int el)
{
	if (isEmpty())
		throw new exception("List is empty");
	DListNode* tmp = findNodePtr(el);
	if (tmp == NULL)
		throw new exception("DListNode doesn't exist");
	if (tmp->next == NULL)
		throw new exception("Element doesn't have next DListNode");
	return tmp->next->info;
}

int DList::getPreviousEl(int el)
{
	if (isEmpty())
		throw new exception("List is empty");
	DListNode* tmp = findNodePtr(el);
	if (tmp == NULL)
		throw new exception("DListNode doesn't exist");
	if (tmp->prev == NULL)
		throw new exception("Element doesn't have previous DListNode");
	return tmp->prev->info;
}

bool DList::isInList(int el)
{
	if (isEmpty())
		return false;
	DListNode* tmp = findNodePtr(el);
	if (tmp == NULL)
		return false;
	else
		return true;
}

void DList::deleteEl(int el)
{
	if (!isEmpty())
		if (head->isEqual(el))
		{
			DListNode* tmp = head;
			head = head->next;
			head->prev = NULL;
			delete tmp;
		}
		else
		{
			DListNode* tmp;
			for (tmp = head->next; tmp != NULL && !(tmp->isEqual(el)); tmp = tmp->next);
			if (tmp != NULL)
			{
				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;
				delete tmp;
			}
		}
}

void DList::addToHead(int el)
{
	head = new DListNode(el, NULL, head);
	if (head->next != NULL)
		head->next->prev = head;
}

void DList::addToTail(int el)
{
	if (!isEmpty())
	{
		DListNode* tmp = head;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new DListNode(el, tmp, NULL);
	}
	else
		addToHead(el);
}

int DList::deleteFromHead()
{
	if (isEmpty())
		throw new exception("List is empty");
	int el = head->info;
	DListNode* tmp = head;
	head = head->next;
	if (head != NULL)
		head->prev = NULL;
	delete tmp;
	return el;
}

int DList::deleteFromTail()
{
	if (isEmpty())
		throw new exception("List is empty");
	int el;
	if (head->next == NULL)
	{
		return deleteFromHead();
	}
	else
	{
		DListNode* tmp = head;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		el = tmp->info;
		tmp->prev->next = NULL;
		delete tmp;
	}
	return el;
}

void DList::printAll()
{
	DListNode* tmp = head;
	while (tmp != NULL)
	{
		cout << tmp->print() << " ";
		tmp = tmp->next;
	}
	cout << endl;
}


//KOLOKVIJUM 2023 - DVOLANCANO RADJEN
int DList::swapPairs(int data1, int data2)
{
	DListNode* cur;
	int brojIteracija = 0;
	for (cur = head; cur != NULL && cur->info != data1; cur = cur->next);
	if (cur != NULL)
	{
		DListNode* prev = cur->prev;
		DListNode* fut = cur->next;


		while (cur->next != NULL && cur->info != data2)
		{
			//izlancavanje
			prev->next = fut;
			fut->prev = prev;

			//ulancavanje
			fut->next->prev = cur;
			cur->next = fut->next;
			fut->next = cur;
			cur->prev = fut;

			//update pointer
			prev = cur;
			cur = cur->next;
			fut = cur->next;
			brojIteracija++;
		}
	}
	return brojIteracija;
}





//KOLOKVIJUM 2021
void DList::exchange(int data1, int data2)
{
	DListNode* cur1 = head;
	while (cur1 != NULL && cur1->info != data1)
		cur1 = cur1->next;
	if (cur1 == NULL)
		throw "Prvi element ne pripada nizu";

	DListNode* cur2 = cur1->next;
	while (cur2 != NULL && cur2->info != data2)
		cur2 = cur2->next;
	if (cur2 == NULL)
		throw"Drugi element ne pripada nizu";


	DListNode* prev1 = cur1->prev;
	DListNode* prev2 = cur2->prev;

	DListNode* next1 = cur1->next;
	DListNode* next2 = cur2->next;


	//ulancavanje data2
	if (prev1 != NULL)//ako data1 nije prvi element
		prev1->next = cur2;
	else//ako data1 jeste prvi element
		head = cur2;

	if (next1 != cur2)//ako nisu jedan pored drugog
	{
		next1->prev = cur2;
		cur2->next = next1;
	}
	else//ako su jedan pored drugog
	{
		next1->prev = prev1;
		cur2->next = cur1;
	}

	cur2->prev = prev1;



	//ulancavanje data1
	prev2->next = cur1;
	if (next2 != NULL)//ako data2 nije zadnji element
		next2->prev = cur1;

	if (cur1 != prev2)//ako nisu jedan pored drugog
		cur1->prev = prev2;
	else//ako su jedan pored drugog
		cur1->prev = cur2;

	cur1->next = next2;
}