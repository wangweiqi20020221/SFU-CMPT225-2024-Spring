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
    int size;

    Node<type>* root;
public:
    bool insert(type item);
    bool remove(type item);

    int getHeight();
    int getSize();

    Node<type>* getRoot();
    Node<type>* find(type item, Node<type>* node = this->getRoot());

    void display();
    void display(Node<type>* node);
    void swapNode(Node<type>* node1, Node<type>* node2);
};

template<typename type>
int Heap<type>::getHeight() {

}

template<typename type>
int Heap<type>::getSize() {
    return this->size;
}

template<typename type>
Node<type>* Heap<type>::getRoot() {
    return this->root;
}

template<typename type>
Node<type>* Heap<type>::find(type item, Node<type>* node = this->getRoot()) {
    if(node == nullptr) {
        return nullptr;
    }
    if(node->getData() < item) {
        return this->find(item, node->left);
    } else if(node->getData() > item) {
        return this->find(item, node->right);
    } else {
        return node;
    }
}

template<typename type>
void Heap<type>::display() {
    this->display(this->getRoot());
}

template<typename type>
void Heap<type>::display(Node<type>* node) {
    if(node->left != nullptr) {
        node->left->display();
    }
    if(node->right != nullptr) {
        node->right->display();
    }
    cout << node->getData();
}
