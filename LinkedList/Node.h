//  Node.h
//  Created by Melissa Trevino

template <class T>
class node {
	public:
		node();
	    node(T data);
	    node(T data, node<T> *tnext);
	    // T getData();
	    // node<T>* getNext();
	    // void setData(T data);
	    // void setNext(node<T> *next);
	    T data;
	    node<T> *next;
};

template <class T>
node<T>::node(){
    this->next = nullptr;
}
template <class T>
node<T>::node(T data){
    this->data = data;
    this->next = nullptr;
}

template <class T>
node<T>::node(T data, node<T> *next){
    this->data = data;
    this->next = next;
}

// template <class T>
// T node<T>::getData(){
// 	return this->data;
// }

// template <class T>
// node<T>* node<T>::getNext(){
// 	return this->next;
// }

// template <class T>
// void node<T>::setData(T data){
// 	this->data = data;
// }

// template <class T>
// void node<T>::setNext(node<T> *next){
// 	this->next = next;
// }