#pragma once

#ifndef LABA_4_QUEUE_H
#define LABA_4_QUEUE_H
#include "TNodik.h"

class Queue
{
public:
	Queue() {
		first = nullptr;
		last = nullptr;
	}
	~Queue() {
		delete first;
		delete last;
	}
	void Add_Q(int value) {
		TNode* tmp = new TNode[value];
		if (first == nullptr) {
			first = tmp;
			last = tmp;
		}
		else {
			last->setNext(tmp);
			last = tmp;
		}
	}

	int front() {
		if (first == nullptr) {
			return -1; //
		}
		else {
			int a = first->getInfo();
			TNode* q = first;
			first = first->getNext();
			q->setNext(0);
			delete q;
			if (first == nullptr) {
				last = nullptr;
			}
			return a;
		}
	}
	Queue (const Queue& tmp) {
		if (tmp.first == nullptr) {
			first = nullptr;
			last = nullptr;
		}
		else {
			first = new TNode(tmp.first->getInfo());
			last = first;
			TNode* current = tmp.first->getNext();
			while (current != nullptr) {
				TNode* p = new TNode[current->getInfo()];
				last->setNext(p);
				last = p;
				current = current->getNext();
			}
		}
	}


private:
	TNode* first;
	TNode* last;
};
#endif
