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

    // pointer to the left sub-node
    Node* left;
    // pointer to the right sub-nodes
    Node* right;

    string taskID;

    type data;
public:
    Node(Node<type>* left, Node* right, type* data);

    bool isLeave();

    int getDepth();
    int getPriority();

    Node& getLeft();
    Node& getRight();

    type getData();

    string getTaskID();

    void setData(type data);
    void setDepth(int depth);
    void setPriority(int priority);
    void setTaskID(string taskID);
};

template<typename type>
Node<type>::Node(Node<type>* left, Node<type>* right, type* data) {
    this->left = left;
    this->right = right;
    this->setData(data);
}

template<typename type>
bool Node<type>::isLeave() {
    if(this->left == nullptr && this->right == nullptr) {
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
Node<type>& Node<type>::getLeft() {
    return this->left;
}

template<typename type>
Node<type>& Node<type>::getRight() {
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
void Node<type>::setPriority(int priority) {
    this->priority = priority;
}

template<typename type>
void Node<type>::setTaskID(string taskID) {
    this->taskID = taskID;
}
