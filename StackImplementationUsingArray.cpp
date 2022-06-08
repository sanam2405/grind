// Stack class.
class Stack {
    
public:
    
    int *arr;
    int cap;
    int idx;
    Stack(int capacity) {
        arr = new int[capacity];
        cap = capacity;
        idx = -1;
    }

    void push(int num) {
        idx++;
        if(idx < cap)
        arr[idx] = num;
    }

    int pop() {
        if(idx >= 0 && idx < cap)
        return arr[idx--];
        return -1;
    }
    
    int top() {
        if(idx >= 0 && idx < cap)
        return arr[idx];
        return -1;
    }
    
    int isEmpty() {
        return idx==-1;
    }
    
    int isFull() {
        return idx>=cap;
    }
    
};
