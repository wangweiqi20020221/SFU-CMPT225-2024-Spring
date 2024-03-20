/* IPQ Class
 * Author: Weiqi Wang
 * ID: 301417203
 * Date: 10:00 pm, Friday March 29
 */

#include <iostream>
#include <vector>

#include "Heap.h"

template<typename type>
class IPQ{
    /* M: A map links id to Node*
     * Heap: A Binary Tree to storage nodes
     */
    private:
        Heap<type> heap;

        unordered_map<string, Node*> indexedHeap;

    public:
        IPQ();
        IPQ(vector<string> PQ);

        // Return true if the PQ is empty, otherwise false.
        bool isEmpty();

        // Return the number of tasks in the PQ.
        int size();

        // Remove all tasks from the PQ.
        void clear();
        // Insert task ID tid with priority p.
        void insert(const std::string & tid, int p);
        // change the priority for task tid to p.
        void updatePriority(const std::string & tid, int p);
        // remove the task with ID tid from the PQ
        void remove(const std::string & tid);
        // Changes the heap array size to be max{i,10}
        void reserve(int i);

        // Remove and return (a reference to) a task ID with smallest priority.
        std::string & deleteMin();
        // Return (a reference to) a task ID with the smallest priority.
        std:: string & getMin();
};

template<typename type>
bool IPQ<type>::isEmpty() {
    return this->heap.getSize() == 0;
}