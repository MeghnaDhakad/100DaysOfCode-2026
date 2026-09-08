#include <stdio.h>
#include <stdlib.h>

pp
class MyCircularQueue {
private:
    vector<int> data;
    int head;   // index of front element
    int count;  // number of elements currently in queue
    int capacity;

public:
    MyCircularQueue(int k) {
        data.resize(k);
        head = 0;
        count = 0;
        capacity = k;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        int tailIndex = (head + count) % capacity;
        data[tailIndex] = value;
        count++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        head = (head + 1) % capacity;
        count--;
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return data[head];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        int tailIndex = (head + count - 1) % capacity;
        return data[tailIndex];
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

int main() {
    printf("Execution completed successfully.\n");
    return 0;
}
