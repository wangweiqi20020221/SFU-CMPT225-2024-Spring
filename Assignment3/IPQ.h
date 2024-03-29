/* IPQ Class
 * Author: Weiqi Wang
 * ID: 301417203
 * Date: 10:00 pm, Friday March 29
 */

#include <iostream>
#include <unordered_map>
#include <vector>

#include "Heap.h"

class IPQ{
/* M: A map links id to Node*
 * Heap: A Binary Tree to storage nodes
 */
private:
    Heap<int> heap;

    std::unordered_map<std::string, Node<int>*> indexedHeap;

public:
    IPQ();
    IPQ(std::vector<std::string> taskID, std::vector<int> priority);
    ~IPQ();

    // Return true if the PQ is empty, otherwise false.
    bool isEmpty();

    // Return the number of tasks in the PQ.
    int size();

    // Remove and return (a reference to) a task ID with the smallest priority.
    std::string& deleteMin();
    // Return (a reference to) a task ID with the smallest priority.
    std::string& getMin();

    // Remove all tasks from the PQ.
    void clear();
    // Insert task ID tid with priority p.
    void insert(const std::string& tid, int p);
    // change the priority for task tid to p.
    void updatePriority(const std::string& tid, int p);
    // remove the task with ID tid from the PQ
    void remove(const std::string& tid);
    // Changes the heap array size to be max{i,10}
    void reserve(int i);
};

IPQ::IPQ() {
    /* Parameterless constructor
     */
}

IPQ::IPQ(std::vector<std::string> taskID, std::vector<int> priority) {
    /* Parameter constructor
     */
    for(int i = 0; i < taskID.size(); i++) {
        this->insert(taskID[i], priority[i]);
    }
}

IPQ::~IPQ() {
    /* Destructor.
     */
    this->clear();
}

bool IPQ::isEmpty() {
    /* Return true if the IPQ is empty.
     * Otherwise, return false.
     */
    return this->indexedHeap.empty();
}

int IPQ::size() {
    /* Return the size of the IPQ.
     */
    return this->indexedHeap.size();
}

std::string& IPQ::deleteMin() {
    /* Delete the node with smallest priority.
     * Return the task id of this node.
     */
    std::string taskID = this->getMin();
    this->remove(this->getMin());
    return taskID;
}

std::string& IPQ::getMin() {
    /* Return the task id of the node with smallest priority.
     */
    std::string* minTaskID;
    for(std::unordered_map<std::string, Node<int>*>::iterator it = this->indexedHeap.begin(); it != indexedHeap.end(); it++) {
        if(it->second == this->heap.getRoot()) {
            minTaskID = const_cast<std::string*>(&it->first);
            return* minTaskID;
        }
    }
}

void IPQ::clear() {
    /* Clear the IPQ.
     */
    heap.clear();
    this->indexedHeap.clear();
}

void IPQ::insert(const std::string& tid, int p) {
    /* Insert a node to the IPQ by taskID and priority.
     */
    this->indexedHeap[tid] = this->heap.insert(p);
}

void IPQ::updatePriority(const std::string& tid, int p) {
    /* Update a node's priority.
     */
    if(this->indexedHeap[tid] != nullptr) {
        if(this->heap.remove(this->indexedHeap[tid]->getData())) {
            this->indexedHeap[tid] = this->heap.insert(p);
        }
    }
}

void IPQ::remove(const std::string &tid) {
    /* Removes a node by its taskID.
     */
    if(this->heap.remove(this->indexedHeap[tid]->getData())) {
        this->indexedHeap.erase(tid);
    }
}

void IPQ::reserve(int i) {
    /* Isn't use because the heap is not arrey based.
     */
}
