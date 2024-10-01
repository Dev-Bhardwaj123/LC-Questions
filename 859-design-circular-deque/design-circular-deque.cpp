class MyCircularDeque {
public:
    vector<int> v;
    int front,back,size,cap;
    MyCircularDeque(int k) {
        v=vector<int>(k,-1);
        front=0;
        back=0;
        size=0;
        cap=k;
    }
    
    bool insertFront(int value) {
        if(isFull()){
            return false;
        }
        if(front==0){
            front=cap-1;
        }
        else{
            front--;
        }
        v[front]=value;
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }

        v[back] = value;
        if (back == cap - 1) {
            back = 0;
        } 
        else {
            back++; 
        }

        size++;
        return true;
    }
    
    bool deleteFront() {
         if (isEmpty()) {
            return false;
        }
        v[front] = -1;
        if (front == cap - 1) {
            front = 0;
        } 
        else {
            front++;
        }

        size--;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }

        if (back == 0) {
            back = cap - 1;
        } 
        else 
        {
            back--;
        }
        v[back] = -1;
        
        size--;
        return true;
    }
    
    int getFront() {
        if(isEmpty()){
            return -1;
        }
        return v[front];
    }
    
    int getRear() {
        if (isEmpty()){return -1;} 
        if (back == 0) {
            return v[cap - 1];
        } 
        else {
            return v[back - 1];
        }
    }
    
    bool isEmpty() {
        return (size==0);
    }
    
    bool isFull() {
        return (size==cap);
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */