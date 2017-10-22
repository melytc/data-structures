//  Node.h
//  Created by Melissa Trevino

template <class T>
class node {
	public:
		node();
	    node(T data);
	    node(T data, node<T> *tnext);
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