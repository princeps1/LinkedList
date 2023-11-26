#include"DList.h"

void main()
{
	try
	{
		DList* list = new DList();


		//KOLOKVIJUM 2023 - DVOLANCANO RADJEN
		/*list->addToHead(0);
		list->addToHead(9);
		list->addToHead(8);
		list->addToHead(7);
		list->addToHead(6);
		list->addToHead(5);
		list->addToHead(4);
		list->addToHead(3);
		list->addToHead(2);
		list->addToHead(1);

		cout << "list pre funkcije: ";
		list->printAll();
		cout << endl;

		cout << "list posle funkcije: ";

		int a = list->swapPairs(4, 8);

		list->printAll();
		cout << "Broj iteracija: " << a;*/



		//KOLOKVIJUM 2021
		/*list->addToHead(9);
		list->addToHead(8);
		list->addToHead(7);
		list->addToHead(6);
		list->addToHead(5);
		list->addToHead(4);
		list->addToHead(3);
		list->addToHead(2);
		list->addToHead(1);

		cout << "list pre funkcije: ";
		list->printAll();
		cout << endl;

		list->exchange(1,9);
		cout << "list posle funkcije: ";
		list->printAll();
		cout << endl;*/



	}

	catch (const char* textic)
	{
		cout << textic;
	}
}