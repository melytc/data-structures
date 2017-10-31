template <class T>

class Node {
public:
    Node(T newData) {
        this->data = newData;
        this->left = nullptr;
        this->right = nullptr;
    }

    void setData(T newData) {
        this->data = newData;
    }

    void setLeft(Node *newLeft) {
        this->left = newLeft;
    }

    void setRight(Node *newRight) {
        this->right = newRight;
    }

    T getData() {
        return data;
    }

    Node* getLeft(){
        return left;
    }

    Node* getRight() {
        return right;
    }
    
private:
    T data;
    Node *left;
    Node *right;
}