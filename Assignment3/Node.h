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
    int priority;

    Node* left;   // pointer to the left sub-node
    Node* right;  // pointer to the right sub-nodes

    string taskID;

    type data;
public:
    Node(type data, int depth);
    Node(type data, int depth, Node<type>* left, Node<type>* right);

    bool isLeave();

    int getDepth();
    int getPriority();

    Node<type>* getLeft();
    Node<type>* getRight();

    type getData();

    string getTaskID();

    void setData(type data);
    void setDepth(int depth);
    void setLeft(Node<type>* node);
    void setRight(Node<type>* node);
    void setPriority(int priority);
    void setTaskID(string taskID);
};

template<typename type>
Node<type>::Node(type data, int depth) {
    this->setLeft(nullptr);
    this->setRight(nullptr);
    this->setData(data);
    this->setDepth(depth);
}

template<typename type>
Node<type>::Node(type data, int depth, Node<type>* left, Node<type>* right) {
    this->setLeft(left);
    this->setRight(right);
    this->setData(data);
    this->setDepth(depth);
}

template<typename type>
bool Node<type>::isLeave() {
    if(this->getLeft() == nullptr && this->getRight() == nullptr) {
        return true;
    } else {
        return false;
    }
}

template<typename type>
int Node<type>::getDepth() {
    return this->depth;
}

template<typename type>
int Node<type>::getPriority() {
    return this->priority;
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
type Node<type>::getData() {
    return this->data;
}

template<typename type>
string Node<type>::getTaskID() {
    return this->taskID;
}

template<typename type>
void Node<type>::setData(type data) {
    this->data = data;
}

template<typename type>
void Node<type>::setDepth(int depth) {
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
void Node<type>::setPriority(int priority) {
    this->priority = priority;
}

template<typename type>
void Node<type>::setTaskID(string taskID) {
    this->taskID = taskID;
}
