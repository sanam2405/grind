class Queue {
public:
    
    vector<int> q;
    int head = 0;
    int tail = 0;
    Queue() {
        // Implement the Constructor
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        return head==tail;
    }

    void enqueue(int data) {
        q.push_back(data);
        tail++;
    }

    int dequeue() {
        if(head==tail)
            return -1;
        return q[head++];
    }

    int front() {
        if(head==tail)
            return -1;
        return q[head];
    }
};
