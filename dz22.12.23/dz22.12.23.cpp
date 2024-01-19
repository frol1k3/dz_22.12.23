#include "List.h"
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "");

	List* l1 = new List();
	l1->pushFront(8);
	l1->pushFront(5);
	l1->pushBack(21);
	l1->pushFront(24);
	l1->pushFront(20);
	l1->pushBack(34);

	cout << "Вывод списка: ";
	l1->traverse();

	l1->popFront();
	l1->popBack();

	cout << "Вывод списка: ";
	l1->traverse();

	l1->insert(l1->getFront()->next, 9);

	cout << "Вывод списка: ";
	l1->traverse();

	l1->erase(l1->getFront()->next);

	cout << "Вывод списка: ";
	l1->traverse();

	l1->clear();

	cout << "Вывод списка: ";
	l1->traverse();
}