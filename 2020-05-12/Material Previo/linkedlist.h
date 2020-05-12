#pragma once
#include <stdexcept>
#include "objetobase.h"

using T = ObjetoBase*;

struct Node {
	T data;
	Node* next;
};

class LinkedList {
 private:
	Node* first;
	friend class Iterator;
 public:
	LinkedList() {
		this->first = nullptr;
	}

	~LinkedList() {
		Node* aux;
		while (this->first) {
			aux = this->first;
			this->first = this->first->next;
			delete aux;
		}
	}

	void push(T data) {
		if (!this->first) {
			this->first = new Node{data, nullptr};
		} else {
			Node* aux = this->first;
			while (aux->next) {
			aux = aux->next;
			}
			aux->next = new Node{data, nullptr};
		}
	}

	T pop() {
		if (!this->first) {
			throw std::runtime_error("Cannot pop an empty LinkedList");
		} else {
			T data;
			if (!this->first->next) {
				data = this->first->data;
				delete this->first;
				this->first = nullptr;
			} else {
				Node* aux = this->first;
				while (aux->next->next) {
				aux = aux->next;
			}
				Node* to_delete = aux->next;
				data = to_delete->data;
				delete to_delete;
				aux->next = nullptr;
			}
			return data;
		}
	}

	T operator [] (int k) {
		Node* aux = this->first;
		for (int i = 0; i < k; ++i)
			aux = aux->next;
		if (!aux)
			throw std::runtime_error("LinkedList doesn't have that object");
		return aux->data;
	}
};

class Iterator {
public:
	Iterator(LinkedList* list) {
		this->current = list->first;
	}
	virtual ~Iterator() = default;
	bool hasFinished() {
		return this->current == nullptr;
	}
	T getCurrent() {
		return this->current->data;
	}
	void goNext() {
		this->current = this->current->next;
	}
private:
	Node* current;
};
