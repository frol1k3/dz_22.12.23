#pragma once
class ListNode {
public:
	int data;
	ListNode* next;
	ListNode* previous;
	ListNode(int data);
};

class List {
public:
	ListNode* front;
	ListNode* back;


	List();
	bool isEmpty();
	ListNode* getFront();
	ListNode* getBack();
	void pushFront(int data);
	void popFront();
	void pushBack(int data);
	void popBack();
	void insert(ListNode* node, int data);
	void erase(ListNode* node);
	void traverse();
	void clear();

};
