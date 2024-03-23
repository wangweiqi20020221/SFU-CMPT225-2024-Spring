/* IPQ Class
 * Author: Weiqi Wang
 * ID: 301417203
 * Date: 10:00 pm, Friday March 29
 */
#include <iostream>

using namespace std;

template<typename type>
class Node{
private:
    int depth;
    int index;

    Node<type>* left;   // pointer to the left sub-node
    Node<type>* right;  // pointer to the right sub-nodes
    Node<type>* parent;

    type data;
public:
    Node(const type data, const int depth, const int index, Node<type>* parent = nullptr, Node<type>* left = nullptr, Node<type>* right = nullptr);

    const bool isLeave();

    const int getDepth();
    const int getIndex();

    Node<type>* getLeft();
    Node<type>* getRight();
    Node<type>* getParent();

    const type getData();

    void setData(const type data);
    void setDepth(const int depth);
    void setLeft(Node<type>* node);
    void setRight(Node<type>* node);
    void setParent(Node<type>* node);
    void setIndex(const int index);
};

template<typename type>
Node<type>::Node(const type data, const int depth, const int index, Node<type>* parent, Node<type>* left, Node<type>* right) {
    this->setData(data);
    this->setDepth(depth);
    this->setIndex(index);
    this->setParent(parent);
    this->setLeft(left);
    this->setRight(right);
}

template<typename type>
const bool Node<type>::isLeave() {
    if(this->getLeft() == nullptr && this->getRight() == nullptr) {
        return true;
    } else {
        return false;
    }
}

template<typename type>
const int Node<type>::getDepth() {
    return this->depth;
}

template<typename type>
const int Node<type>::getIndex() {
    return this->index;
}

template<typename type>
Node<type>* Node<type>::getLeft() {
    return this->left;
}

template<typename type>
Node<type>* Node<type>::getRight() {
    return this->right;
}

template<typename type>
Node<type>* Node<type>::getParent() {
    return this->parent;
}

template<typename type>
const type Node<type>::getData() {
    return this->data;
}

template<typename type>
void Node<type>::setData(const type data) {
    this->data = data;
}

template<typename type>
void Node<type>::setDepth(const int depth) {
    this->depth = depth;
}

template<typename type>
void Node<type>::setLeft(Node<type>* node) {
    this->left = node;
}

template<typename type>
void Node<type>::setRight(Node<type>* node) {
    this->right = node;
}

template<typename type>
void Node<type>::setParent(Node<type>* node) {
    this->parent = node;
}

template<typename type>
void Node<type>::setIndex(const int index) {
    this->index = index;
}
