//  LinkedList.h
//  Created by Melissa Trevino
#include "Node.h"

// Forgot to include template tag.
template <class T>
class LinkedList {
	public:
		LinkedList();
		bool add(T, int);
		void deleteFirst();
		void deleteLast();
		T first();
		void frontBackSplit(node<T> **, node<T> **); // forgot a ; at the end, and to declare parameters as a **.
		void insertAt(int, int);
		bool isEmpty();
		void makeEmpty();
		T operator[](int);
		T pop();
		void push(T);
		void pushBack(T);
		int size();

		/*
		bool del(int pos);
		int delAll();
		bool isEmpty();
		bool change(int  pos1, int pos2);
		T getElem(int ipos);
		T setElem(T data, int pos);
		void print();
		T getLast();
		void deleteFirstN(int);
		void reverse();
		void shift(int);
		void spin(int);
		bool operator ==(LinkedList<T> &obj);
		void operator +=(T dato);
		void operator +=(LinkedList<T> &lista);
		LinkedList(LinkedList<T> &l);
	    LinkedList<T> operator =(LinkedList<T> &obj);
	    
	    Comparar extremos
	    Agregar en todas las pos pares algo (avanza 2)
	    Borrar impares (avanza 1) */

		node<T> *root;
}; // forgot a ; after class declaration.

// Forgot to add constructor lol
template <class T>
LinkedList<T>::LinkedList(){
	root = nullptr;
}

template <class T>
bool LinkedList<T>::add(T data, int pos){
	if(pos > size()){
		return false;
	}
	else if(pos == 0) { // forgot to write else if instead of just if
		push(data);
	}
	else if(pos == size()){
		pushBack(data);
	} else{
		node<T> *aux = root;
		
		while(pos > 1){
			aux = aux->next;
			pos--;
		}
		
		aux->next = (new node<T>(data, aux->next));
	}
	return true;
}

template <class T>
void LinkedList<T>::deleteFirst(){
	node<T> *aux = root;
	root = aux->next;
	delete aux;
}

template <class T>
void LinkedList<T>::deleteLast(){
	node<T> *aux = root;
	while(aux->next->next != nullptr){
		aux = aux->next;
	}
	node<T> *last = aux->next;
	aux->next = nullptr;
	delete last;
}

// Added template header to all methods.
template <class T>
T LinkedList<T>::first(){
	return root->data;
}

template <class T>
void LinkedList<T>::frontBackSplit(node<T> **front, node<T> **back) {
	// forgot case when size() is 1, and both pointers should be pointing to the same node (root).
	if(size() == 1){
		*front = root;
		*back = root;
	} else{
		node<T> *aux = new node<T>;
		aux->next = root;	
		node<T> *frontAux = aux;
		node<T> *backAux = aux;

		// When trying to divde the list, move front pointer once and back pointer twice.
		while(backAux != nullptr && backAux->next != nullptr){
			backAux = backAux->next->next;
			frontAux = frontAux->next;
		}

		*back = frontAux->next;
		frontAux->next = nullptr;
		*front = root;
	}
}

template <class T>
void LinkedList<T>::insertAt(int iIndex, int iElem){
	if(root == nullptr)
		throw 1; // throw integer to refer to error.

	node<T> *aux = root;
	if(iIndex == 0)
		push(iElem);
	else{
		while(iIndex > 1){
			aux = aux->next;
			iIndex--;
		}

		// no need to add <T> when referring the name of the variable.
		node<T> *others = aux->next;
		node<T> *newnode = new node<T>(); // consistency in class name Node != node
		newnode->data = iElem;
		newnode->next = others;
		aux->next = newnode;
	}
}

template <class T>
bool LinkedList<T>::isEmpty(){
	return root == nullptr;
}

template <class T>
void LinkedList<T>::makeEmpty(){
	node<T> *head = root;
	node<T> *next = root->next;

	while(next != nullptr){
		delete head;
		head = next;
		next = next->next;
	}

	delete head;
	root = nullptr;
}

template <class T>
T LinkedList<T>::operator[](int iPosition){
	node<T> *aux = root;

	while(iPosition != 0 && aux != nullptr){
		aux = aux->next;
		iPosition--;
	}

	if(aux==nullptr)
		throw 1;

	return aux->data;
}

template <class T>
void LinkedList<T>::push(T iNew){
	// Forgot to initialize first as a node object.
	node<T> *first = new node<T>();
	first->data = iNew;
	first->next = root;
	root = first;
}

template <class T>
T LinkedList<T>::pop(){
	node<T> *aux = root;
	root = root->next;
	int iElem = aux->data;
	delete aux;
	return iElem;
}

template <class T>
void LinkedList<T>::pushBack(T iElem){
	node<T> *back = new node<T>();
	back->data = iElem;
	back->next = nullptr;

	node<T> *aux = root;
	// Consider the case where root is null (the list is empty)
	if(root == nullptr){
		root = back;
		return;
	}
	while(aux->next != nullptr){
		aux = aux->next;
	}

	aux->next = back;
}

template <class T>
int LinkedList<T>::size(){
	int iCount = 0;
	node<T> *aux = root;

	while(aux != nullptr){
		iCount++;
		aux = aux->next;
	}
	return iCount;
}