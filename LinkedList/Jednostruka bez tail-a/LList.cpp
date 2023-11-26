#include "LList.h"


LList::LList()
{
	head = NULL;
}


LList::~LList()
{
	while (!isEmpty())
	{
		int tmp = deleteFromHead();
	}
}


bool LList::isEmpty()
{
	return head == NULL;
}

void LList::addToHead(int el)
{
	head = new LListNode(el, head);
}

void LList::addToTail(int el)
{
	if (!isEmpty())
	{
		LListNode* tmp = head;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new LListNode(el);
	}
	else
		addToHead(el);
}

int LList::deleteFromHead()
{
	if (isEmpty())
		throw new exception("List is empty");
	int el = head->info;
	LListNode* tmp = head;
	head = head->next;
	delete tmp;
	return el;
}

int LList::deleteFromTail()
{
	if (isEmpty())
		throw new exception("List is empty");
	int el;
	if (head->next == NULL)
	{
		el = head->info;
		delete head;
		head = NULL;
	}
	else
	{
		LListNode* prev = head;
		LListNode* tmp = head;
		while (tmp->next != NULL)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		el = tmp->info;
		delete tmp;
		prev->next = NULL;
	}
	return el;
}

LListNode* LList::findNodePtr(int el)
{
	if (isEmpty())
		throw new exception("List is empty");
	LListNode* ret = head;
	while (ret != NULL && ret->info != el)
	{
		ret = ret->next;
	}
	return ret;
}

LListNode* LList::getHead()
{
	return head;
}

LListNode* LList::getNext(LListNode* ptr)
{
	if (isEmpty())
		throw new exception("List is empty");
	return ptr->next;
}

int LList::getHeadEl()
{
	if (isEmpty())
		throw new exception("List is empty");
	return head->info;
}

int LList::getNextEl(int el)
{
	if (isEmpty())
		throw new exception("List is empty");
	LListNode* tmp = findNodePtr(el);
	if (tmp == NULL)
		throw new exception("LListNode doesn't exist");
	if (tmp->next == NULL)
		throw new exception("Element doesn't have next LListNode");
	return tmp->next->info;
}

void LList::printAll()
{
	LListNode* tmp = head;
	while (tmp != NULL)
	{
		cout << tmp->print() << " ";
		tmp = tmp->next;
	}
	cout << endl;
}

bool LList::isInList(int el)
{
	if (isEmpty())
		return false;
	LListNode* tmp = findNodePtr(el);
	if (tmp == NULL)
		return false;
	else
		return true;
}

void LList::deleteEl(int el)
{
	if (!isEmpty())
		if (head->isEqual(el))
		{
			LListNode* tmp = head;
			head = head->next;
			delete tmp;
		}
		else
		{
			LListNode* pred, * tmp;
			for (pred = head, tmp = head->next; tmp != NULL && !(tmp->isEqual(el));
				pred = pred->next, tmp = tmp->next);
			if (tmp != NULL)
			{
				pred->next = tmp->next;
				delete tmp;
			}
		}
}

LListNode* LList::removeNodeFromHead()
{
	if (isEmpty())
		return NULL;
	LListNode* tmp = head;
	head = head->next;
	return tmp;
}


//KOLOKVIJUM 2023 A-GRUPA
int LList::swapPairs(int data1, int data2)
{
	LListNode* prev;
	LListNode* cur;
	int brPromena = 0;

	if (head->info != data1)
		for (prev = head, cur = head->next; cur != NULL && cur->info != data1; prev = prev->next, cur = cur->next);
	else
	{
		prev = NULL;
		cur = head;
	}
	if (cur->info == data1)//naso data1
	{

		while (cur != NULL && cur->info != data2)
		{
			if (prev == NULL)
			{
				head = cur->next;
				cur->next = cur->next->next;
				prev = head;
				prev->next = cur;

				//update pointers
				prev = head->next;
				cur = cur->next;
				brPromena++;
			}
			else
			{
				prev->next = cur->next;
				cur->next = cur->next->next;
				prev->next->next = cur;

				//update pointers
				prev = cur;
				cur = cur->next;
				brPromena++;
			}
		}
	}
	else
	{
		return 0;
	}
	return brPromena;
}







//JUN 2021
LList* LList::extraEven()
{

	LList* listPom = new LList();

	//u slucaju da su svi brojevi parni
	while (head != NULL && head->info % 2 == 0)
	{
		//ulancavanje u novu lancanu listu
		listPom->addToHead(head->info);
		//ulancavanje stare lancane liste
		head = head->next;
	}

		LListNode* cur = head;
		LListNode* prev = head;

	while (cur != NULL)
	{
		if (cur->info % 2 == 0)
		{
			//ulancavam u novu lancanu listu
			listPom->addToHead(cur->info);

			//ulancavanje stare lancane liste
			prev->next = cur->next;

			//update
			cur = prev->next;
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}

	LList* listPom2 = new LList();
	listPom2 = swap(listPom);
	
	return listPom2;
}
LList* LList::swap(LList* listPom)
{
	LListNode* cur = listPom->head;
	LList* listPom2 = new LList();
	while (cur != NULL)
	{
		listPom2->addToHead(cur->info);
		cur = cur->next;
	}
	return listPom2;
}








//JUN 2022
void LList::GroupElements()
{
	LListNode* cur1 = head;

	while (cur1 != NULL)
	{
		LListNode* prev2 = cur1;
		LListNode* cur2 = cur1->next;

		while (cur2 != NULL)
		{
			if (cur1->info == cur2->info)
			{
				//ulancavanje
				prev2->next = cur2->next;
				cur2->next = cur1->next;
				cur1->next = cur2;

				//update pointers
				cur1 = cur2;
				prev2 = cur2;
				cur2 = cur2->next;
			}
			else
			{
				prev2 = prev2->next;
				cur2 = cur2->next;
			}
		}
		cur1 = cur1->next;
	}
}


//KOLOKVIJUM I 2023 B-GRUPA
void LList::invertSublist(int data1, int data2)
{
	if (head == NULL)
		throw "Prazna lista";

	LListNode* prev1 = head;
	LListNode* cur1;
	if (prev1->info == data1)
	{
		cur1 = prev1;
		prev1 = NULL;
	}
	else
	{
		while (prev1->next != NULL && prev1->next->info != data1)
			prev1 = prev1->next;

		if (prev1->next == NULL)
			throw "Data1 ne postoji u listi";

		cur1 = prev1->next;
	}
	//
	LListNode* prev2 = cur1;
	while (prev2->next != NULL && prev2->next->info != data2)
	{
		prev2 = prev2->next;
	}
	if (prev2->next == NULL)
		throw "Data2 ne postoji u listi";

	LListNode* cur2 = prev2->next;

	bool kraj = false;
	while (!kraj)
	{
		//izlancavanje
		if (prev1 != NULL)
			prev1->next = cur1->next;
		else
			head = head->next;
		prev2->next = cur2->next;

		//ulancavanje za cur2
		if (prev1 != NULL)
		{
			cur2->next = prev1->next;
			prev1->next = cur2;
		}
		else
		{
			cur2->next = head;
			head = cur2;
		}

		//ulancavanje za cur1
		cur1->next = prev2->next;
		prev2->next = cur1;


		//update pointers
		prev1 = cur2;
		cur1 = prev1->next;

		cur2 = prev2;
		prev2 = cur1;
		if (cur1 != cur2)
		{
			while (prev2->next != cur2)//
				prev2 = prev2->next;
		}
		else if (cur1 == cur2)
		{
			kraj = true;
			break;
		}
		if (prev2 == cur1)
		{
			//izlancavanje
			prev1->next = cur2->next;

			//ulancavanje cur2
			cur2->next = prev1->next;
			prev1->next = cur2;

			//ulancavanje cur1
			cur1->next = cur2->next;
			cur2->next = cur1;

			kraj = true;
		}
	}

}

//JUN2 2022
LList* LList::SplitOrMove()
{
	LList* newList = new LList();

	LListNode* cur1 = head;
	LListNode* prev1 = NULL;
	LListNode* cur2 = cur1->next;
	LListNode* prev2 = head;

	while (cur2 != NULL && cur2->info != cur1->info)
	{
		prev2=cur2;
		cur2 = cur2->next;
	}

	if (cur2 == NULL)
	{
		do
		{
			//izlancavanje
			head = cur1->next;

			//ulancavanje u novu listu
			newList->addToHead(cur1->info);

			//update
			cur1 = head;
			prev2 = head;
			if(cur1!=NULL)
			cur2 = cur1->next;

			while (cur2 != NULL && cur2->info != cur1->info)
			{
				prev2 = cur2;
				cur2 = cur2->next;
			}
		} while(cur2 == NULL && cur1!=NULL);
	}



	else if (cur1 !=NULL && cur2 != NULL)
	{
		//izlancavanje
		prev2->next = cur2->next;

		//ulancavanje u novu listu
		newList->addToHead(cur2->info);

		//update pinters
		prev1 = cur1;
		cur1 = cur1->next;
		prev2 = cur1;
		cur2 = cur1->next;
	}



	while (cur1 != NULL)
	{
		while (cur2 != NULL && cur2->info != cur1->info)
		{
			prev2 = cur2;
			cur2 = cur2->next;
		}

		if (cur2 == NULL)
		{
			//izlancavanje
			prev1->next = cur1->next;

			//ulancavanje u novu listu
			newList->addToHead(cur1->info);

			//update pointers
			cur1 = prev1->next;
			if (cur1 != NULL)
				cur2 = cur1->next;
			prev2 = cur1;
		}
		else
		{
			prev2->next = cur2->next;

			//ulancavanje u novu listu
			newList->addToHead(cur2->info);

			//update pointers
			prev1 = cur1;
			cur1 = cur1->next;
			prev2 = cur1;
			if(cur1!=NULL)
				cur2 = cur1->next;
		}
	}
	return newList;
}







//JUN2 2021
void LList::injectOrRemove(int br)
{
	if (head == NULL)
		throw"Prazna lista";

	LListNode* newNode = new LListNode(br);

	if (head->info > br)
	{
		newNode->next = head;
		head = newNode;
		return;
	}
	else if(head->info==br)
	{
		head = head->next;
		return;
	}


	LListNode* cur = head;
	while (cur->next != NULL &&cur->next->info != br  && cur->next->info < br)
		cur = cur->next;

	//ulancavanje na kraju
	if (cur->next == NULL)
		cur->next = newNode;

	//slucaj brisanja
	else if (cur->next->info == br )
		cur->next = cur->next->next;

	//ulancavanje novog cvora na sredini
	else if (cur->next->info > br)
	{
		newNode->next = cur->next;
		cur->next = newNode;
	}
}