/*
Queue : 선입선출(FIFO) : enqueue(추가) / dequeue(제거) / front(제거없이 가져오기)
      : isEmpty(비어있는지 확인) / size(큐의 크기)
*/
#include<iostream>

class Node {
    public : 
        int data;
        Node* next;

        Node(int value) : data(value), next(nullptr) {}
};

// Queue class : First In First Out
class Queue{
    private:
        Node* front;
        Node* rear;
    
    public:
        Queue() : front(nullptr), rear(nullptr) {}

        void push(int value){
            Node* newNode = new Node(value);
            if (rear == nullptr){
                front = rear = newNode;
            }
            else{
                rear->next = newNode;
                rear = newNode;
            }
        }

        void pop(){
            if(isempty()){
                std::cout << "Queue is empty.";
                return;
            }
            // else
            Node* temp = front;
            front = front->next;
            delete temp;

            if (front == nullptr){
                rear = nullptr;
            }
        }

        int Front(){
            if (isempty()){
                std::cout << "Queue is empty.";
                return -1;
            }
            // else
            return front->data;
        }

        bool isempty(){
            return front == nullptr;
        }

        int size(){
            int cnt = 0;;
            Node* curr = front;
            while (curr != nullptr){
                cnt++;
                curr = curr->next;
            }
            return cnt;
        }

        void display(){
            Node* curr = front;
            while (curr != nullptr){
                std::cout << curr->data << " ";
                curr = curr->next;
            }
            std::cout << "\n";
            
        }
        ~Queue(){
            while (!isempty()){
                pop();
            }
        }
};

int main(){
    Queue Q;
    Q.push(0);
    Q.push(10);
    Q.push(20);
    Q.push(30);
    Q.push(40);
    Q.push(50);

    Q.display();
    std::cout << "front element : " << Q.Front() << "\n";
    std::cout << "Queue size : " << Q.size() << "\n";

    while (!Q.isempty()){
        std::cout << Q.Front() << "\n";
        Q.pop();
    }
}

