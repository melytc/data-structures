#include "Node.h"
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

// Corrections
//  1 - forgot to define Node as Node<T> when creating a pointer or a node.

template <class T>
class BinaryTree {
private:
    Node<T> *root;

public:
    BinaryTree() {
        root = nullptr;
    }

    bool insert(T newData) {
        if(root == nullptr) {
            root = new Node<T>(newData);
        } else {
            Node<T> *aux = root;
            Node<T> *father = nullptr;

            while(aux != nullptr) {
                if(aux->getData() == newData)
                    return false;
                
                father = aux;
                aux = (newData > aux->getData())? aux->getRight() : aux->getLeft();
            }

            (newData > father->getData())? father->setLeft(new Node<T>(newData)) :  father->setRight(new Node<T>(newData));
        }
        return true;
    }

    bool contains(T newData) {
        Node<T> *aux = root;

        while(aux != nullptr) {
            if(aux->getData() == newData)
                return true;
            aux = (newData > aux->getData())? aux->getRight() : aux->getLeft();
        }
        return false;
    }

    void preorderR(Node<T> *t) {
        if(t != nullptr) {
            cout << t->getData() << " ";
            preorderR(t->getLeft());
            preorderR(t->getRight());
        }
    }

    void inorderR(Node<T> *t) {
        if(t != nullptr) {
            inorderR(t->getLeft());
            cout << t->getData() << " ";
            inorderR(t-getRight());
        }
    }

    void postorderR(Node<T> *t) {
        if(t != nullptr) {
            postorderR(t->getLeft());
            postorderR(t->getRight());
            cout << t->getData() << " ";
        }
    }

    void printLeaves(Node<T> *t) {
        if(t != nullptr) {
            if(t->getRight() == nullptr && t->getLeft() == nullptr)
                cout << t->getData();
            else {
                printLeaves(t->getLeft());
                printLeaves(t->getRight());
            }
        }
    }

    void preorderI(Node<T> *t) {
        Node<T> *aux = nullptr;
        stack<Node<T> *> nodeStack;
        nodeStack.push(t);
        
        while(nodeStack.size() > 0) {
            aux = nodeStack.top();
            cout << aux->getData() << " ";
            nodeStack.pop();

            // Push right node first so that the left one sits at the top.
            if(aux->getRight() != nullptr)
                nodeStack.push(aux->getRight());

            if(aux->getLeft() != nullptr)
                nodeStack.push(aux->getLeft());
        }
        delete aux;
    }

    void print(int iOrder) {
        switch(iOrder) {
            case 1:
                preorderR(root);
                break;
            case 2:
                inorderR(root);
                break;
            case 3:
                postorderR(root);
                break;
            case 4:
                printLeaves(root);
        }
        cout << endl;
    }

    int countR(Node<T> *t) {
        if(t == nullptr)
            return 0;
        else
            return 1 + countR(t->getLeft()) + countR(t->getRight());
    }

    int count() {
        return countR(root);
    }

    int heightR(Node<T> *t) {
        (t == nullptr)? return 0 : return 1 + max(heightR(t->getLeft()), heightR(t->getRight()));
    }

    int height() {
        return heightR(root);
    }

    int howManyChildren(Node<T> *t) {
        if(t == nullptr || (t->getLeft() == nullptr && t->getRight() == nullptr))
            return 0;
        else {
            return ((t->getLeft() == nullptr)? 0 : howManyChildren(t->getLeft()) + 1) + ((t->getRight() == nullptr) ? 0 : howManyChildren(t->getRight()) + 1);
        } 
    }

    int predecessor(Node<T> *t) {
        if(t == nullptr)
            return 0;
        else {
            (t->getLeft() == nullptr)? return 0 : t = t->getLeft();
            while(t->getRight() != nullptr)
                t = t->getRight();
            
            return t->getData();
        }
    }

    int successor(Node<T> *t) {
        if(t == nullptr)
        return 0;
    else {
        (t->getRight() == nullptr)? return 0 : t = t->getRight();
        while(t->getLeft() != nullptr)
            t = t->getLeft();
        
        return t->getData();
    }

    bool delete(T deleteThis) {
        if(root == nullptr) {
            return false;
        } else {
            Node<T> *aux = root;
            Node<T> *father = nullptr;

            while(aux != nullptr && aux->getData() != deleteThis) {
                father = aux;
                aux = (deleteThis < aux->getData())? aux->getLeft() : aux->getRight();
            }

            if(aux == nullptr)
                return false;
            else {
                int iChildren = howManyChildren(aux);
                switch(iChildren) {
                    case 0:
                        if(father == nullptr)
                            root = nullptr;
                        else
                            (father->getData() > deleteThis)? father->setLeft(nullptr) : father->setRight(nullptr);
                        delete aux;
                        break;
                    case 1:
                        if(father == nullptr)
                            root = (aux->getLeft() == null)? aux->getRight() : aux->getLeft();
                        else {
                            if(father->getData() > deleteThis) {
                                if (aux->getLeft() != nullptr)
                                    father->setLeft(aux->getLeft());
                                else
                                    father->setLeft(aux->getRight());
                            } else {
                                if (aux->getLeft() != nullptr)
                                    father->setRight(aux->getLeft());
                                else
                                    father->setRight(aux->getRight());
                            }
                        }
                        delete aux;
                        break;
                    case 2:
                        int iData = predecessor(aux);
                        delete(iData);
                        aux->setData(iData);
                        break;
                }
                return true;
            }
        }
    }
}