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
    bool remove(const type data);

    const int getHeight();
    const int getHeight(Node<type>* node);
    const int getSize();
    const int getSize(Node<type>* node);

    Node<type>* getRoot();
    Node<type>* getLastLeaf();
    Node<type>* getLastLeaf(Node<type>* node);
    Node<type>* find(const type data);
    Node<type>* find(const type data, Node<type>* node);
    Node<type>* insert(const type data);
    Node<type>* insert(const type data, Node<type>* node);

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
bool Heap<type>::remove(const type data) {
    Node<type>* node = this->find(data);
    if(node == nullptr) {
        return false;
    } else if(node == this->getRoot() && this->getSize() == 1) {
        delete node;
        this->setRoot(nullptr);
        return true;
    }
    Node<type>* lastLeaf = this->getLastLeaf();
    this->swapNode(node, lastLeaf);
    if(node->getParent()->getLeft() == node) {
        node->getParent()->setLeft(nullptr);
    } else {
        node->getParent()->setRight(nullptr);
    }
    delete node;
    this->percolateDown(lastLeaf);
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
    if(node->isLeaf()) {
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
    if(node->isLeaf()) {
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
Node<type>* Heap<type>::getLastLeaf() {
    /* Find the last leaf of the heap
     */
    return this->getLastLeaf(this->getRoot());
}

template<typename type>
Node<type>* Heap<type>::getLastLeaf(Node<type>* node) {
    if(node->getLeft() != nullptr && node->getRight() != nullptr) {
        Node<type>* node1 = this->getLastLeaf(node->getLeft());
        Node<type>* node2 = this->getLastLeaf(node->getRight());
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
        return this->getLastLeaf(node->getLeft());
    } else if(node->getLeft() == nullptr && node->getRight() != nullptr) {
        return this->getLastLeaf(node->getRight());
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
Node<type>* Heap<type>::insert(const type data) {
    /* Insert a data to the heap.
     * If the heap currently contains the data, return the node address of the data.
     * If not, insert it and returns its address.
     */
    Node<type>* searchResult = this->find(data);
    if(searchResult != nullptr) {
        return searchResult;
    }

    if(this->getRoot() == nullptr) {
        Node<type>* newNode = new Node<type>(data, 0, 0);
        this->setRoot(newNode);
        return newNode;
    }

    Node<type>* insertResult = this->insert(data, this->getRoot());
    if(insertResult != nullptr) {
        return insertResult;
    } else {
        Node<type>* node = this->getRoot();
        while(node->getLeft() != nullptr) {
            node = node->getLeft();
        }
        Node<type>* newNode = new Node<type>(data, node->getDepth() + 1, this->getSize() + 1, node);
        node->setLeft(newNode);
        this->percolateUp(newNode);
        return newNode;
    }
}

template<typename type>
Node<type>* Heap<type>::insert(const type data, Node<type>* node) {
    /* Insert the node to the sub-node of a leaf
     */
    if(node->getLeft() != nullptr && node->getRight() != nullptr) {
        Node<type>* insertLeftResult = this->insert(data, node->getLeft());
        if(insertLeftResult != nullptr) {
            return insertLeftResult;
        }

        Node<type>* insertRightResult = this->insert(data, node->getRight());
        if(insertRightResult != nullptr) {
            return insertRightResult;
        }
        return nullptr;

    } else if(node->getLeft() != nullptr && node->getRight() == nullptr) {
        Node<type>* newNode = new Node<type>(data, node->getDepth() + 1, this->getSize() + 1, node);
        node->setRight(newNode);
        this->percolateUp(newNode);
        return newNode;
    }

    if(node->isLeaf() && node->getDepth() < this->getHeight()) {
        Node<type>* newNode = new Node<type>(data, node->getDepth() + 1, this->getSize() + 1, node);
        node->setLeft(newNode);
        this->percolateUp(newNode);
        return newNode;
    }
    return nullptr;
}

template<typename type>
void Heap<type>::clear() {
    while(this->getRoot() != nullptr) {
        this->extractMin();
    }

}

template<typename type>
void Heap<type>::display() {
    std::cout << "[";
    for(int depth = 0; depth <= this->getHeight(); depth++) {
        display(depth, this->getRoot());
    }
    std::cout << "]" << std::endl;
}

template<typename type>
void Heap<type>::display(const int depth, Node<type>* node) {
    if(node->getDepth() == depth) {
        std::cout << node->getData() << ", ";
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
void Heap<type>::percolateUp(Node<type>* node) {
    /* If the parent of the node is greater than the node, swap these two nodes,
     * until the parent of the node is smaller than the node or node is the root node.
     *
     * Returns the address of the node after percolate up.
     */
    if(node != this->getRoot()) {
        if(node->getData() < node->getParent()->getData()) {
            this->swapNode(node, node->getParent());
            if(!node->isLeaf()) {
                percolateUp(node);
            }
        }
    }
}

template<typename type>
void Heap<type>::percolateDown(Node<type>* node) {
    /* If the child of the node is smaller than the node, swap these two nodes,
     * until the parent of the node is greater than the node or node is leaf.
     *
     * Returns the address of the node after percolate up.
     */
    if(node->getLeft() != nullptr) {
        if(node->getLeft()->getData() < node->getData()) {
            this->swapNode(node, node->getLeft());
            if(!node->isLeaf()) {
                percolateDown(node);
            }
        }
    }
    if(node->getRight() != nullptr) {
        if(node->getRight()->getData() < node->getData()) {
            this->swapNode(node, node->getRight());
            if(!node->isLeaf()) {
            }
        }
    }
}

template<typename type>
void Heap<type>::setRoot(Node<type>* node) {
    this->root = node;
}

template<typename type>
void Heap<type>::swapNode(Node<type>* node1, Node<type>* node2) {
    /* Swap two nodes.
     * Nodes keep the data, just reset the address of root, parent, child
     */
    if(node1->getParent() == nullptr) {
        this->setRoot(node2);
    } else if(node1->getParent() != node2) {
        if(node1->getParent()->getLeft() == node1) {
            node1->getParent()->setLeft(node2);
        } else {
            node1->getParent()->setRight(node2);
        }
    }
    if(node1->getLeft() != nullptr) {
        if(node1->getLeft() != node2) {
            node1->getLeft()->setParent(node2);
        }
    }
    if(node1->getRight() != nullptr) {
        if(node1->getRight() != node2) {
            node1->getRight()->setParent(node2);
        }
    }
    if(node2->getParent() == nullptr) {
        this->setRoot(node1);
    } else if(node2->getParent() != node1) {
        if(node2->getParent()->getLeft() == node2) {
            node2->getParent()->setLeft(node1);
        } else {
            node2->getParent()->setRight(node1);
        }
    }
    if(node2->getLeft() != nullptr) {
        if(node2->getLeft() != node1) {
            node2->getLeft()->setParent(node1);
        }
    }
    if(node2->getRight() != nullptr) {
        if(node2->getRight() != node1) {
            node2->getRight()->setParent(node1);
        }
    }

    int tempDepth = node1->getDepth();
    int tempIndex = node1->getIndex();
    Node<type>* tempParent;
    if(node1->getParent() == nullptr) {
        tempParent = nullptr;
    } else if(node1->getParent() == node2) {
        tempParent = node1;
    } else {
        tempParent = node1->getParent();
    }
    Node<type>* tempLeft;
    if(node1->getLeft() == nullptr) {
        tempLeft = nullptr;
    } else if(node1->getLeft() == node2) {
        tempLeft = node1;
    } else {
        tempLeft = node1->getLeft();
    }
    Node<type>* tempRight;
    if(node1->getRight() == nullptr) {
        tempRight = nullptr;
    } else if(node1->getRight() == node2) {
        tempRight = node1;
    } else {
        tempRight = node1->getRight();
    }

    node1->setDepth(node2->getDepth());
    node1->setIndex(node2->getIndex());
    if(node2->getParent() == nullptr) {
        node1->setParent(nullptr);
    } else if(node2->getParent() == node1) {
        node1->setParent(node2);
    } else {
        node1->setParent(node2->getParent());
    }
    if(node2->getLeft() == nullptr) {
        node1->setLeft(nullptr);
    } else if(node2->getLeft() == node1) {
        node1->setLeft(node2);
    } else {
        node1->setLeft(node2->getLeft());
    }
    if(node2->getRight() == nullptr) {
        node1->setRight(nullptr);
    } else if(node2->getRight() == node1) {
        node1->setRight(node2);
    } else {
        node1->setRight(node2->getRight());
    }

    node2->setDepth(tempDepth);
    node2->setIndex(tempIndex);
    node2->setParent(tempParent);
    node2->setLeft(tempLeft);
    node2->setRight(tempRight);
}
