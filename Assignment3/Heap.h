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

    bool insert(const type data);
    bool insert(const type data, Node<type>* node);
    bool remove(const type data);

    const int getHeight();
    const int getHeight(Node<type>* node);
    const int getSize();
    const int getSize(Node<type>* node);

    Node<type>* getRoot();
    Node<type>* getLastLeave();
    Node<type>* getLastLeave(Node<type>* node);
    Node<type>* find(const type data);
    Node<type>* find(const type data, Node<type>* node);

    void clear();
    void display();
    void display(const int depth, Node<type>* node);
    void extractMin();
    void makeHeap();
    void makeHeap(Node<type>* node);
    void percolateUp(Node<type>* node);
    void percolateDown(Node<type>* node);
    void setRoot(Node<type>* node);
    void swapNode(Node<type>* node1, Node<type>* node2);
};

template<typename type>
Heap<type>::Heap() {
    this->setRoot(nullptr);
}

template<typename type>
bool Heap<type>::insert(const type data) {
    if(this->find(data) != nullptr) {
        return false;
    }

    if(this->getRoot() == nullptr) {
        Node<type>* newNode = new Node<type>(data, 0, 0);
        this->setRoot(newNode);
        return true;
    }
    
    if(insert(data, this->getRoot())) {
        return true;
    } else {
        Node<type>* node = this->getRoot();
        while(node->getLeft() != nullptr) {
            node = node->getLeft();
        }
        Node<type>* newNode = new Node<type>(data, node->getDepth() + 1, this->getSize() + 1, node);
        node->setLeft(newNode);
        this->percolateUp(newNode);
        return true;
    }
}

template<typename type>
bool Heap<type>::insert(const type data, Node<type>* node) {
    if(node->getLeft() != nullptr && node->getRight() != nullptr) {
        if(this->insert(data, node->getLeft())) {
            return true;
        } else if(this->insert(data, node->getRight())) {
            return true;
        } else {
            return false;
        }
     } else if(node->getLeft() != nullptr && node->getRight() == nullptr) {
        Node<type>* newNode = new Node<type>(data, node->getDepth() + 1, this->getSize() + 1, node);
        node->setRight(newNode);
        this->percolateUp(newNode);
        return true;
    }
    
    if(node->isLeave() && node->getDepth() < this->getHeight()) {
        Node<type>* newNode = new Node<type>(data, node->getDepth() + 1, this->getSize() + 1, node);
        node->setLeft(newNode);
        this->percolateUp(newNode);
        return true;
    }
    return false;
}

template<typename type>
bool Heap<type>::remove(const type data) {
Node<type>* node = this->find(data);
    if(node == nullptr) {
        return false;
    } else if(node == this->getRoot() && this->getSize() == 1) {
        delete node;
        this->setRoot(nullptr);
        return true;
    }
    Node<type>* lastLeave = this->getLastLeave();
    this->swapNode(node, lastLeave);
    if(lastLeave->getParent()->getLeft() == lastLeave) {
        lastLeave->getParent()->setLeft(nullptr);
    } else {
        lastLeave->getParent()->setRight(nullptr);
    }
    delete lastLeave;
    this->percolateDown(node);
    return true;
}

template<typename type>
const int Heap<type>::getHeight() {
    /* Get the height of the heap.
     * If the heap is empty, return -1.
     */
    if(this->getRoot() == nullptr) {
        return -1;
    } else {
        return this->getHeight(this->getRoot());
    }
}

template<typename type>
const int Heap<type>::getHeight(Node<type>* node) {
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
const int Heap<type>::getSize() {
    /* Get the size of the heap.
     * If a heap is empty, return -1.
     */
    if(this->getRoot() == nullptr) {
        return -1;
    } else {
        return this->getSize(this->getRoot());
    }
}

template<typename type>
const int Heap<type>::getSize(Node<type>* node) {
    if(node->isLeave()) {
        return 1;
    } else if(node->getLeft() == nullptr && node->getRight() != nullptr) {
        return this->getSize(node->getRight()) + 1;
    } else if(node->getLeft() != nullptr && node->getRight() == nullptr) {
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
Node<type>* Heap<type>::getLastLeave() {
    return this->getLastLeave(this->getRoot());
}

template<typename type>
Node<type>* Heap<type>::getLastLeave(Node<type>* node) {
    if(node->getLeft() != nullptr && node->getRight() != nullptr) {
        Node<type>* node1 = this->getLastLeave(node->getLeft());
        Node<type>* node2 = this->getLastLeave(node->getRight());
        if(node1 != nullptr && node2 != nullptr) {
            return node2;
        } else if(node1 != nullptr && node2 == nullptr) {
            return node1;
        } else if(node1 == nullptr && node2 != nullptr) {
            return node2;
        } else {
            return nullptr;
        }
    } else if(node->getLeft() != nullptr && node->getRight() == nullptr) {
        return this->getLastLeave(node->getLeft());
    } else if(node->getLeft() == nullptr && node->getRight() != nullptr) {
        return this->getLastLeave(node->getRight());
    } else {
        if(node->getDepth() == this->getHeight()) {
            return node;
        } else {
            return nullptr;
        }
    }
}

template<typename type>
Node<type>* Heap<type>::find(const type data) {
    if(this->getRoot() == nullptr) {
        return nullptr;
    } else {
        return this->find(data, this->getRoot());
    }
}

template<typename type>
Node<type>* Heap<type>::find(const type data, Node<type>* node) {
    if(node == nullptr) {
        return nullptr;
    }
    if(node->getData() == data) {
        return node;
    } else if(node->getData() > data) {
        return nullptr;
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
void Heap<type>::clear() {
    while(this->getRoot() != nullptr) {
        this->extractMin();
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
void Heap<type>::display(const int depth, Node<type>* node) {
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
void Heap<type>::extractMin() {
    this->remove(this->getRoot()->getData());
}

template<typename type>
void Heap<type>::makeHeap() {
    this->makeHeap(this->getRoot());
}

template<typename type>
void Heap<type>::makeHeap(Node<type>* node) {
    this->percolateDown(node);
    if(node->getLeft() != nullptr) {
        makeHeap(node->getLeft());
    }
    if(node->getRight() != nullptr) {
        makeHeap(node->getRight());
    }
}

template<typename type>
void Heap<type>::setRoot(Node<type>* node) {
    this->root = node;
}

template<typename type>
void Heap<type>::percolateUp(Node<type>* node) {
    while(node != this->getRoot() && node->getData() < node->getParent()->getData()) {
        this->swapNode(node, node->getParent());
        node = node->getParent();
    }
}

template<typename type>
void Heap<type>::percolateDown(Node<type>* node) {
    while(node->getLeft() != nullptr || node->getRight() != nullptr) {
        if(node->getLeft() == nullptr) {
            if(node->getRight()->getData() < node->getData()) {
                this->swapNode(node, node->getRight());
                node = node->getRight();
            } else {
                break;
            }
        } else if(node->getRight() == nullptr) {
            if(node->getLeft()->getData() < node->getData()) {
                this->swapNode(node, node->getLeft());
                node = node->getLeft();
            } else {
                break;
            }
        } else {
            Node<type>* tempNode;
            if(node->getLeft()->getData() < node->getRight()->getData()) {
                tempNode = node->getLeft();
            } else {
                tempNode = node->getRight();
            }
            if(tempNode->getData() < node->getData()) {
                this->swapNode(tempNode, node);
            } else {
                break;
            }
            node = tempNode;
        }
    }
}

template<typename type>
void Heap<type>::swapNode(Node<type>* node1, Node<type>* node2) {
    type tempData = node1->getData();
    node1->setData(node2->getData());
    node2->setData(tempData);
}
