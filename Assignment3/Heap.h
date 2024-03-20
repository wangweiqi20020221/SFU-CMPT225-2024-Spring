/* IPQ Class
 * Author: Weiqi Wang
 * ID: 301417203
 * Date: 10:00 pm, Friday March 29
 */
#include <unordered_map>

#include "Node.h"

template<typename type>
class Heap{
private:
    Node<type>* root;
public:
    Heap();

    bool insert(type data);
    bool insert(type data, Node<type>* node);
    bool remove(type data);

    int getHeight();
    int getHeight(Node<type>* node);
    int getSize();
    int getSize(Node<type>* node);

    Node<type>* getRoot();
    Node<type>* find(type data);
    Node<type>* find(type data, Node<type>* node);

    void display();
    void display(int depth, Node<type>* node);
    void percolate_up(Node<type>* node);
    void setRoot(Node<type>* node);
    void swapNode(Node<type>* node1, Node<type>* node2);
};

template<typename type>
Heap<type>::Heap() {
    this->setRoot(nullptr);
}

template<typename type>
bool Heap<type>::insert(type data) {
    if(this->find(data) != nullptr) {
        return false;
    }

    if(this->getRoot() == nullptr) {
        Node<type>* newNode = new Node<type>(data, 0);
        this->setRoot(newNode);
        return true;
    }
    
    if(insert(data, this->getRoot())) {
        return true;
    } else {
        Node<type>* node = this->getRoot();
        while(node->getLeft() != nullptr) {
            if(data < node->getLeft()->getData()) {
                type tempData = node->getLeft()->getData();
                node->getLeft()->setData(data);
                data = tempData;
            }
            node = node->getLeft();
        }
        Node<type>* newNode = new Node<type>(data, node->getDepth() + 1);
        node->setLeft(newNode);
        if(newNode->getData() < node->getData()) {
            this->swapNode(node, newNode);
        }
        return true;
    }
}

template<typename type>
bool Heap<type>::insert(type data, Node<type>* node) {
    if(node->getLeft() != nullptr && node->getRight() != nullptr) {
        if(this->insert(data, node->getLeft())) {
            if(node->getData() > node->getLeft()->getData()) {
                this->swapNode(node, node->getLeft());
            }
            return true;
        } else if(this->insert(data, node->getRight())) {
            if(node->getData() > node->getRight()->getData()) {
                this->swapNode(node, node->getRight());
            }
            return true;
        } else {
            return false;
        }
     } else if(node->getLeft() != nullptr && node->getRight() == nullptr) {
        Node<type>* newNode = new Node<type>(data, node->getDepth() + 1);
        node->setRight(newNode);
        if(node->getData() > newNode->getData()) {
            this->swapNode(node, newNode);
        }
        return true;
    }
    
    if(node->isLeave() && node->getDepth() < this->getHeight()) {
        Node<type>* newNode = new Node<type>(data, node->getDepth() + 1);
        node->setLeft(newNode);
        if(node->getData() > newNode->getData()) {
            this->swapNode(node, newNode);
        }
        return true;
    }
    return false;
}

template<typename type>
int Heap<type>::getHeight() {
    return this->getHeight(this->getRoot());
}

template<typename type>
int Heap<type>::getHeight(Node<type>* node) {
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
int Heap<type>::getSize(Node<type>* node) {
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
Node<type>* Heap<type>::find(type data) {
    if(this->getRoot() == nullptr) {
        return nullptr;
    } else {
        return this->find(data, this->getRoot());
    }
}

template<typename type>
Node<type>* Heap<type>::find(type data, Node<type>* node) {
    if(node == nullptr) {
        return nullptr;
    }
    if(node->getData() == data) {
        return node;
    }

    if(this->find(data, node->getLeft()) == nullptr && this->find(data, node->getRight()) == nullptr) {
        return nullptr;
    } else if(this->find(data, node->getLeft()) == nullptr && this->find(data, node->getRight()) != nullptr) {
        return this->find(data, node->getRight());
    } else {
        return this->find(data, node->getLeft());
    }
}

template<typename type>
void Heap<type>::display() {
    cout << "[";
    for(int depth = 0; depth <= this->getHeight(); depth++) {
        display(depth, this->getRoot());
    }
    cout << "]" << endl;
}

template<typename type>
void Heap<type>::display(int depth, Node<type>* node) {
    if(node->getDepth() == depth) {
        cout << node->getData() << ", ";
    } else {
        if(node->getLeft() != nullptr)  {
            this->display(depth, node->getLeft());
        }
        if(node->getRight() != nullptr) {
            this->display(depth, node->getRight());
        }
    }
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
