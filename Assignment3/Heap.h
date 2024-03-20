/* IPQ Class
 * Author: Weiqi Wang
 * ID: 301417203
 * Date: 10:00 pm, Friday March 29
 */
#include <unordered_map>

#include <Node.h>

template<typename type>
class Heap{
private:

    Node<type>* root;
public:
    bool insert(type data);
    bool remove(type data

    int getHeight();
    int getHeight(Node* node);
    int getSize();
    int getSize(Node* node);

    Node<type>* getRoot();
    Node<type>* find(type data, Node<type>* node = this->getRoot());

    void display();
    void display(int height);
    void setRoot(Node<type>* node);
    void swapNode(Node<type>* node1, Node<type>* node2);
};

template<typename type>
bool Heap<type>::insert(type data) {
    if(this->getRoot() == nullptr) {
        Node<type>* node = new Node<type>;
        node->setData(data);
        this->setRoot(node);
        return true;
    }

    Node<type>* node = this->getRoot();
    if(node == nullptr) {

    }
}

template<typename type>
int Heap<type>::getHeight() {
    return this->getHeight(this->getRoot());
}

template<typename type>
int Heap<type>::getHeight(Node* node) {
    if(node->isLeave()) {
        return 0;
    } else if(node->getLeft() == nullptr) {
        return this->getHeight(node->getRight()) + 1;
    } else if(node->getRight() == nullptr) {
        return this->getHeight(node->getLeft()) + 1;
    }
    if(this->getHeight(node->getLeft()) > this->getHeight(node->getRight())) {
        return this->getHeight(node->getLeft()) + 1;
    } else {
        return this->getHeight(node->getRight()) + 1;
    }
}

template<typename type>
int Heap<type>::getSize() {
    return this->getSize(this->getRoot());
}

template<typename type>
int Heap<type>::getSize(Node* node) {
    if(node->isLeave()) {
        return 1;
    } else if(node->getLeft() == nullptr) {
        return this->getSize(node->getRight()) + 1;
    } else if(node->getRight() == nullptr) {
        return this->getSize(node->getLeft()) + 1;
    } else {
        return this->getSize(node->getLeft()) + this->getSize(node->getRight()) + 1;
    }
}

template<typename type>
Node<type>* Heap<type>::getRoot() {
    return this->root;
}

template<typename type>
Node<type>* Heap<type>::find(type data, Node<type>* node = this->getRoot()) {
    if(node == nullptr) {
        return nullptr;
    } else if(node->getData() == data) {
        return node;
    } else if(this->find(data, node->getLeft()) == data) {
        return this->find(data, node->getLeft());
    } else{
        return this->find(data, node->getRight());
    }
}

template<typename type>
void Heap<type>::display() {
    // do something
}

template<typename type>
void Heap<type>::display(int height) {
    // do something
}

template<typename type>
void Heap<type>::setRoot(Node<type>* node) {
    this->root = node;
}

template<typename type>
void Heap<type>::swapNode(Node<type>* node1, Node<type>* node2) {
    type tempData = node1->getData();
    node1->setData(node2->getData());
    node2->setData(tempData);
}
