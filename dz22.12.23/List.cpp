#include "list.h"
#include <iostream>

ListNode::ListNode(int data) {
	this->data = data;
	this->next = nullptr;
	this->previous = nullptr;
}

List::List() {
	this->front = nullptr;
	this->back = nullptr;
}

bool List::isEmpty() {
	return this->front == nullptr && this->back == nullptr;
}

ListNode* List::getBack() {
	return this->back;
}

ListNode* List::getFront() {
	return this->front;
}

void List::pushFront(int data) {
	ListNode* first = new ListNode(data);
	first->next = this->front;
	if (this->front != NULL)
		this->front->previous = first;
	if (this->back == NULL)
		this->back = first;
	this->front = first;

}

void List::pushBack(int data) {
	ListNode* first = new ListNode(data);
	first->previous = this->back;
	if (this->back != NULL)
		this->back->next = first;
	if (this->front == NULL)
		this->front = first;
	this->back = first;
}

void List::popFront() {
	if (this->front == NULL) return;

	ListNode* ptr = this->front->next;
	if (ptr != NULL)
		ptr->previous = NULL;
	else
		this->back = NULL;

	delete this->front;
	this->front = ptr;
}

void List::popBack() {
	if (this->back == NULL) return;

	ListNode* ptr = this->back->previous;
	if (ptr != NULL)
		ptr->next = NULL;
	else
		this->front = NULL;

	delete this->back;
	this->back = ptr;
}

void List::traverse() {
	ListNode* next = this->front;
	while (next != this->back) {
		std::cout << next->data << " ";
		next = next->next;
	}
	std::cout << this->back->data;
	std::cout << std::endl;
}
void List::insert(ListNode* node, int data) {
	ListNode* ptr = node->next;
	node->next = new ListNode(data);
	node->next->next = ptr;
	node->next->next->previous = node;
}

void List::erase(ListNode* node) {
	ListNode* ptr = node->next->next;
	delete node->next;
	node->next = ptr;
	node->next->previous = node;
}

void List::clear() {
	while (this->front != nullptr) {
		ListNode* next = this->front->next;
		delete this->front;
		this->front = next;
	}
}